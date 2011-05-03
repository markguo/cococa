#include <ace/Signal.h>
#include <stdexcept>

#include "debug.h"
#include "PageFakeServer.hpp"
#include "PageFakeMessage.hpp"

const size_t DEFAULT_BUFSIZE=0x100;
int TServiceConnHandler::open(void * arg)
{
    assert(arg);
    MyAcceptorBase * base = reinterpret_cast<MyAcceptorBase*>(arg);
    MyAcceptor * acceptor = dynamic_cast<MyAcceptor*>(base);
    assert(acceptor!=NULL);
    m_acceptor = acceptor;
    m_reciver = m_acceptor->m_reciver;

    this->peer().get_remote_addr(m_inetRemoteAddr);

    char buffer[1024];
    m_inetRemoteAddr.addr_to_string(buffer, 1024);

    LOG_NOTICE("TServiceConnHandler: Connection from %s established\n", buffer);
    m_peerAddr = buffer;

    m_inbuf.init(DEFAULT_BUFSIZE);

    m_appState = APP_READ_HEADER;
    m_readLeft = sizeof(uint32_t);

    return supper::open(arg);
}

int TServiceConnHandler::handle_close(ACE_HANDLE handle, ACE_Reactor_Mask close_mask)
{
    LOG_NOTICE("TServiceConnHandler: Connnection of %s close.\n", m_peerAddr.c_str());
    reactor()->remove_handler(this, ACE_Event_Handler::READ_MASK
	    |ACE_Event_Handler::WRITE_MASK
	    |ACE_Event_Handler::DONT_CALL);
    return supper::handle_close(handle, close_mask);
}

void TServiceConnHandler::process_message(const char *buf, size_t length)
{
    PageFakeMessage *msg = PageFakeMessage::CreateFromAsn1Msg(buf, length);
    if(!msg){
	LOG_WARNING("Decode msg from %s failed length=%lu\n", m_peerAddr.c_str(), length);
	return;
    }

    assert(m_inetRemoteAddr.get_addr_size() == sizeof(struct sockaddr_in));

    m_reciver->HandleInputMessage(msg);
}

/// Make sure inbuf is large enough
/// for reading bytes of 'require' len
/// if require < 0, reserve a length i think propably.
void TServiceConnHandler::reserve_inbuffer(int require)
{
    if ((size_t)require > m_inbuf.space()) {
	m_inbuf.size(m_inbuf.size() + (require - m_inbuf.space()));
    }
}

int TServiceConnHandler::handle_input(ACE_HANDLE fd)
{
    while(1){

	reserve_inbuffer(m_readLeft);

	int n = peer().recv(m_inbuf.wr_ptr(), m_readLeft); 

	if(n == 0){
	    LOG_ERROR("TServiceConnHandler: remote side closed %s\n", m_peerAddr.c_str());
	    return -1;
	}
	else if (n < 0){
	    // n < 0

	    // Blocking errors are okay, just move on
	    if (errno == EAGAIN || errno == EWOULDBLOCK) {
		return 0;
	    }

	    if (errno != ECONNRESET) {
		LOG_ERROR("TServiceConnHandler::handle_input() recv -1 errno==%d\n", errno);
		return -1;
	    }
	}

	// n > 0
	// Move along in the buffer
	m_inbuf.wr_ptr(n);
	m_readLeft -= n;

	switch(m_appState){
	    case APP_READ_HEADER:
		assert(m_inbuf.length() <= sizeof(uint32_t));
		if(m_readLeft == 0){
		    assert(m_inbuf.length() == sizeof(uint32_t));
		    m_bodylen = *(uint32_t*)m_inbuf.rd_ptr();
		    m_readLeft = m_bodylen;
		    m_inbuf.rd_ptr(sizeof(uint32_t));
		    m_appState = APP_READ_BODY;
		}

		break;

	    case APP_READ_BODY:

		if(m_readLeft == 0){
		    process_message(m_inbuf.rd_ptr(), m_inbuf.length());
		    m_inbuf.reset();
		    m_inbuf.crunch();
		    m_appState = APP_READ_HEADER;
		    m_readLeft = sizeof(uint32_t);
		    return 0;
		}

		break;

	    default:
		assert(false);
	}
    }
    return 0;
}

void PageFakeServer::HandleInputMessage(PageFakeMessage *msg)
{
    ACE_Message_Block *msg_block = new ACE_Message_Block((const char *)msg, sizeof(PageFakeMessage));
    if(putq(msg_block, NULL) == -1 ){
	if (errno == ESHUTDOWN){
	    LOG_WARNING("DROP_INPUT_SPIDER_MSG %s action(%s) ShutingDown\n",
		    msg->url, msg->action);
	}

	// TODO: drop and leaks
    }
}

PageFakeServer::PageFakeServer(uint16_t port, size_t input_msg_queue_max)
:ACE_Task<ACE_MT_SYNCH>(ACE_Thread_Manager::instance(), NULL),
    m_acceptor(this),
    m_port(port),
    m_input_queue_max(input_msg_queue_max)
{
}

PageFakeMessage *PageFakeServer::PopMessage()
{
    static ACE_Time_Value zero_timeout;
    ACE_Message_Block *msg_block = NULL;
    int left = 0;
    if((left = getq(msg_block, &zero_timeout)) == -1){
	return NULL;
    }

    PageFakeMessage *msg = (PageFakeMessage *)msg_block->base();
    delete msg_block;
    return msg;
}

int PageFakeServer::open()
{
    msg_queue()->high_water_mark(m_input_queue_max);
    return activate(THR_SCOPE_SYSTEM);
}

void PageFakeServer::stop()
{
    m_reactor.end_reactor_event_loop();
}

int PageFakeServer::svc()
{
    ACE_INET_Addr listenaddr(m_port);

    m_reactor.owner(ACE_Thread::self());

    if(m_acceptor.open(listenaddr, &m_reactor, ACE_NONBLOCK) < 0){
	char msg[1024];
	snprintf(msg, sizeof(msg), "%s: Open acceptor on port(%d) failed\n", __FUNCTION__, m_port);
	throw std::runtime_error(msg);
    }

    LOG_NOTICE("PageFakeServer listening on port %d\n", m_port);
    LOG_NOTICE("PageFakeServer reactor start\n");
    if(m_reactor.run_reactor_event_loop() == -1){
	return -1;
    }

    LOG_NOTICE("PageFakeServer reactor exit, errno==%d, %s\n", errno, ACE_OS::strerror(errno));

    return 0;
}
