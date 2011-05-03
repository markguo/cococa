/**
 *    \file   PageFakeClient.cpp
 *    \brief  
 *    \date   04/28/11
 *    \author guoshiwei (guoshiwei@gmail.com)
 */

#include <ace/Signal.h>
#include <stdexcept>

#include "debug.h"
#include "SpiderMsgDeliver.hpp"
#include "LocalAux.h"
#include "Spider.hpp"

ASN1_IMPL_MODULE(ASN1_MODULE_NAME, V_ASN1_TP_IMPLICIT_TAGS);

ASN1_IMPL_MODULE_BODY_BEGIN(ASN1_MODULE_NAME) {
    ASN1_BIND_SEQUENCE_BEGIN(ReferInfo) {
	ASN1_BIND_FIELD_SIMPLE(m_ReferIsUrllibSeed),
	ASN1_BIND_FIELD_SIMPLE(m_ReferUrllibID),
	ASN1_BIND_FIELD_SIMPLE(m_ReferUrllibGroupID),
	ASN1_BIND_SEQUENCE_NULL_EXTENSION(),
    } ASN1_BIND_SEQUENCE_END(ReferInfo);

    ASN1_BIND_SEQUENCE_BEGIN(DispatchInfo) {
	ASN1_BIND_FIELD_SIMPLE(m_Origin),
	ASN1_BIND_FIELD_SIMPLE(m_SrcCycle),
	ASN1_BIND_SEQUENCE_NULL_EXTENSION(),
    } ASN1_BIND_SEQUENCE_END(DispatchInfo);

    ASN1_BIND_SEQUENCE_BEGIN(SpiderMsg){
	ASN1_BIND_FIELD_SIMPLE(sender_cycle),
	ASN1_BIND_FIELD_SIMPLE(url_generate_info),
	ASN1_BIND_FIELD_SIMPLE(msg_type),
	ASN1_BIND_FIELD_SIMPLE(url),
	ASN1_BIND_FIELD_STRING_PTR(extension_length, extension),
	ASN1_BIND_FIELD_PTR_OPT(refer_info),
	ASN1_BIND_FIELD_STRING_PTR(feedback_header_length, feedback_header),
	ASN1_BIND_SEQUENCE_NULL_EXTENSION(),
    } ASN1_BIND_SEQUENCE_END(SpiderMsg);

}ASN1_IMPL_MODULE_BODY_END(ASN1_MODULE_NAME);
#undef ASN1_MODULE_NAME

asn1::asn1_allocator * Asn1Allocator()
{
    static asn1::asn1_allocator * a = new asn1::asn1_malloc_allocator;
    return a;
}
/**
 * Decode cmd which is in inbuf, shift rd_ptr() propobly.
 * Throw TProcessorException if somthing wrong.
 */
    template<typename CmdT>
bool decodeCmd(CmdT &cmd, const char *buf, size_t len)
{
    ::asn1::ASN1_RET_CODE r = ::asn1::asn1_ber_decode(Asn1Allocator(), &cmd, (const byte *)buf, len);
    return r == asn1::R_ASN1_OK;
}

/**
 * Encode cmd , put result into outbuf, and shift wd_ptr() propobly.
 * Throw TProcessorException if somthing wrong.
 */
    template <typename CmdT>
bool encodeCmd(const CmdT &cmd, ACE_Message_Block *outbuf)
{
    // encode
    long output_len = 0;
    asn1::ASN1_RET_CODE r = asn1::asn1_ber_encode(&cmd, NULL, &output_len);
    if( r == asn1::R_ASN1_BUFFER_NOT_ENOUGH){
    }

    //FIXME: Strange, asn1 want some bytes more.
    output_len +=32;

    if(outbuf->space() < (unsigned long) output_len){
	outbuf->size(outbuf->size() + output_len - outbuf->space());
    }

    r = asn1::asn1_ber_encode(&cmd, (byte *)outbuf->wr_ptr(), &output_len);
    if(r != asn1::R_ASN1_OK){
	return false;
    }

    outbuf->wr_ptr(output_len);
    return true;
}

void SpiderMsg::SetRemoteAddr(const struct sockaddr_in * addr, size_t addr_len)
{
    assert(addr_len == sizeof(struct sockaddr_in));
    assert(!remote_addr);
    remote_addr = new sockaddr_in;
    memcpy(remote_addr, addr, addr_len);
}

ACE_Message_Block * SpiderMsg::CreateForDispatch(const DispatchInfo &dispatch_info, const UrlInfo &urlinfo)
{
    SpiderMsg msg;
    std::string url = urlinfo.Uri().ToString();
    msg.msg_type = SPIDER_MSG_FETCH_REQUEST;

    // Use original dispatch info.
    if(urlinfo.GetDispatchInfo()){
	msg.url_generate_info = *urlinfo.GetDispatchInfo();
    }
    else{
	msg.url_generate_info = dispatch_info;
    }

    msg.sender_cycle = dispatch_info.m_SrcCycle;
    msg.url = (char *)url.c_str();


    msg.extension = (uint8_t *)urlinfo.GetInternalCommonRequestExtension();
    msg.extension_length = urlinfo.GetExtensionLength();

    msg.refer_info = (ReferInfo *)urlinfo.GetReferInfo();

    ACE_Message_Block *msg_block = new ACE_Message_Block;
    if(!encodeCmd(msg, msg_block)){
	LOG_NOTICE("Encode %s msg failed\n", url.c_str());
	msg.clear();
	delete msg_block;
	return NULL;
    }

    msg.clear();
    return msg_block;
}

ACE_Message_Block * SpiderMsg::CreateForFeedbackResult(const DispatchInfo &dispatch_info, const feedback_header_t &header, const std::string &url)
{
    SpiderMsg msg;

    msg.msg_type = SPIDER_MSG_FETCH_RESULT;
    msg.url_generate_info = dispatch_info;

    msg.sender_cycle = dispatch_info.m_SrcCycle;
    msg.url = (char *)url.c_str();

    msg.feedback_header = (uint8_t *)&header;
    msg.feedback_header_length = sizeof(header);

    ACE_Message_Block *msg_block = new ACE_Message_Block;
    if(!encodeCmd(msg, msg_block)){
	LOG_NOTICE("Encode %s msg failed\n", url.c_str());
	msg.clear();
	delete msg_block;
	return NULL;
    }

    msg.clear();
    return msg_block;
}

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
    SpiderMsg *msg = SpiderMsg::CreateFromAsn1Msg(buf, length);
    if(!msg){
	LOG_WARNING("Decode msg from %s failed length=%lu\n", m_peerAddr.c_str(), length);
	return;
    }

    assert(m_inetRemoteAddr.get_addr_size() == sizeof(struct sockaddr_in));

    msg->SetRemoteAddr((const struct sockaddr_in *)m_inetRemoteAddr.get_addr(), m_inetRemoteAddr.get_addr_size());

    if(msg->msg_type != SpiderMsg::SPIDER_MSG_FETCH_REQUEST
	    && msg->msg_type != SpiderMsg::SPIDER_MSG_FETCH_RESULT){

	LOG_ERROR("BAD_SPIDERMSG %s TServiceConnHandler Unknow msg_type(%d)\n",
		msg->url, msg->msg_type);
	delete msg;
	return;
    }

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

int TClientConnHandler::open(void * arg)
{
    assert(arg);

    ACE_INET_Addr remote_addr;
    this->peer().get_remote_addr(remote_addr);
    char buffer[1024];
    remote_addr.addr_to_string(buffer, 1024);

    LOG_NOTICE("TClientConnHandler: Connection to %s succeed\n", buffer);
    m_peerAddr = buffer;
    int ret = supper::open(arg);
    m_needReconnect = false;
    reactor()->register_handler(this, ACE_Event_Handler::WRITE_MASK);
    return ret;
}

int TClientConnHandler::handle_close(ACE_HANDLE handle, ACE_Reactor_Mask close_mask)
{
    LOG_TRACE("TClientConnHandler: Connection to %s close.\n", m_peerAddr.c_str());
    shutdown();
    m_needReconnect = true;
    ACE_Time_Value timeout(5);
    reactor()->schedule_timer(this, NULL, timeout);
    return 0;
}


int TClientConnHandler::handle_timeout(const ACE_Time_Value &current_time, const void * act)
{
    ACE_Synch_Options synch_options(ACE_Synch_Options::USE_REACTOR);

    TClientConnHandler *handler = this;
    if(m_connector->connect(handler, m_remoteAddr, synch_options) < 0){
	if (errno != EWOULDBLOCK)
	    return -1;
    }

    char buffer[1024];
    m_remoteAddr.addr_to_string(buffer, 1024);
    LOG_TRACE("TClientConnHandler: Reconnect to %s\n", buffer);
    return 0;
}

int TClientConnHandler::handle_input(ACE_HANDLE fd)
{
    LOG_NOTICE("Recv data on TClientConnHandler, the server side is closed\n");
    return -1;
}

int TClientConnHandler::handle_output(ACE_HANDLE fd)
{
    static ACE_Time_Value zero_time;
    if(m_appState == STATE_WAIT_TASK){
	assert(m_sendingMsg == NULL);
	assert(m_sendLeft == 0);
	int n = getq(m_sendingMsg, &zero_time);
	if (n < 0){
	    this->reactor()->cancel_wakeup(this, ACE_Event_Handler::WRITE_MASK);
	    return 0;
	}

	m_appState = STATE_SEND_HEADER;
	m_header = m_sendingMsg->length();
	m_sendLeft = sizeof(m_header);
    }

    while(1){

	const char *send_buf = NULL;
	switch(m_appState){
	    case STATE_SEND_HEADER:
		assert(m_sendLeft <= sizeof(uint32_t));
		send_buf = (const char *) &m_header;
		send_buf += (sizeof(m_header) - m_sendLeft);

		break;

	    case STATE_SEND_BODY:
		assert(m_sendLeft == m_sendingMsg->length());
		send_buf = m_sendingMsg->rd_ptr();
		break;

	    default:
		assert(false);
	}

	int n = peer().send(send_buf, m_sendLeft); 

	if(n == 0){
	    LOG_ERROR("TClientConnHandler::handle_output remote side closed %s\n", m_peerAddr.c_str());
	    return -1;
	}
	else if (n < 0){
	    // n < 0

	    // Blocking errors are okay, just move on
	    if (errno == EAGAIN || errno == EWOULDBLOCK) {
		return 0;
	    }

	    LOG_ERROR("TClientConnHandler::handle_output write -1 errno=%d %s\n", errno, strerror(errno));
	    return -1;
	}

	// n > 0
	// Move along in the buffer
	m_sendLeft -= n;
	switch(m_appState){
	    case STATE_SEND_HEADER:
		assert(m_sendLeft <= sizeof(m_header));
		if(m_sendLeft == 0){
		    m_sendLeft = m_sendingMsg->length();
		    m_appState = STATE_SEND_BODY;
		}

		break;

	    case STATE_SEND_BODY:
		m_sendingMsg->rd_ptr(n);

		if(m_sendLeft == 0){
		    delete m_sendingMsg;
		    m_sendingMsg = NULL;
		    m_appState = STATE_WAIT_TASK;
		    return 0;
		}

		break;

	    default:
		assert(false);
	}
    }
    return 0;
}

SpiderMsgDeliver::SpiderMsgDeliver(Spider *spider, const std::vector<std::string>& members, const std::string& ifname, uint16_t port,
	size_t output_quque_max)
:ACE_Task<ACE_MT_SYNCH>(ACE_Thread_Manager::instance(), NULL),
    m_Spider(spider),
    m_output_msg_queue_max(output_quque_max),
    m_connector(this), m_Members(members.size())
{
    // get local address
    struct sockaddr_in local_address;
    memset(&local_address, 0, sizeof(local_address));
    local_address.sin_family = AF_INET;
    local_address.sin_port = htons(port);
    if (getifaddr(AF_INET, 0, ifname.c_str(), &local_address.sin_addr) != 0)
    {
	throw std::runtime_error("SpiderComm: Can't get self address");
    }

    for (size_t i = 0; i < members.size(); ++i)
    {
	size_t colon = members[i].find(':');
	if (colon == std::string::npos)
	    throw std::runtime_error("SpiderComm: Invalid address " + members[i]);

	m_Members[i].address.set(members[i].c_str(), AF_INET);
	m_Members[i].host_name = members[i].substr(0, colon);
	m_Members[i].client_conn = new TClientConnHandler(m_Members[i].address, &m_connector, m_output_msg_queue_max);
    }

    // get rank of self.
    for (size_t i = 0; i < m_Members.size(); ++i)
    {
	if (memcmp(m_Members[i].address.get_addr(), &local_address, sizeof(local_address))==0)
	{
	    m_self_index = i;
	    LOG_NOTICE("SpiderMsgDeliver SelfIndex == %lu\n", i);
	    return;
	}
    }

    LOG_NOTICE("SpiderMsgDeliver SelfIndex == -1\n");
    m_self_index = -1;
}
int SpiderMsgDeliver::open()
{
    return activate(THR_SCOPE_SYSTEM);
}

int SpiderMsgDeliver::svc()
{
    m_reactor.owner(ACE_Thread::self());
    if(m_connector.open(&m_reactor, ACE_NONBLOCK) < 0){
	char msg[1024];
	snprintf(msg, sizeof(msg), "%s: Open connector failed\n", __FUNCTION__);
	throw std::runtime_error(msg);
    }

    ACE_Synch_Options synch_options(ACE_Synch_Options::USE_REACTOR);

    ACE_SOCK_Connector::PEER_ADDR addr_any;
    for (size_t i = 0; i < m_Members.size(); ++i){
	Member &m = m_Members[i];

	TClientConnHandler *handler = m.client_conn;
	if(m_connector.connect(handler, m.address, synch_options) < 0){
	    if (errno != EWOULDBLOCK){
		LOG_ERROR("Start connect to %s failed\n", m.host_name.c_str());
		return -1;
	    }
	}
    }

    LOG_NOTICE("SpiderMsgDeliver reactor start\n");
    ACE_Time_Value timeout(0, 50000);
    while(1){
	if(m_reactor.run_reactor_event_loop(timeout) != -1){
	    if(m_reactor.reactor_event_loop_done())
		break;

	    for (size_t i = 0; i < m_Members.size(); ++i){
		TClientConnHandler *handler = m_Members[i].client_conn;

		if (!handler->msg_queue()->is_empty())
		    m_reactor.schedule_wakeup(handler, ACE_Event_Handler::WRITE_MASK);
	    }

	    timeout.set(0, 50000);
	}
	else{
	    if(errno == EINTR)
		continue;

	    break;
	}
    }

    LOG_NOTICE("SpiderMsgDeliver reactor exit\n");
    return 0;
}

void SpiderMsgDeliver::stop()
{
    m_reactor.end_reactor_event_loop();
}

bool SpiderMsgDeliver::ValidDeliveringMessage(const char * buf, size_t length)
{
    SpiderMsg *msg = SpiderMsg::CreateFromAsn1Msg(buf, length);
    if(!msg){
	LOG_ERROR("BAD_SPIDERMSG ValidDeliveringMessage_FAIL length=%lu\n", length);
	return false;
    }

    if(msg->msg_type != SpiderMsg::SPIDER_MSG_FETCH_REQUEST
	    && msg->msg_type != SpiderMsg::SPIDER_MSG_FETCH_RESULT){

	LOG_ERROR("BAD_SPIDERMSG %s ValidDeliveringMessage_FAIL Unknow msg_type(%d)\n",
		msg->url, msg->msg_type);
	delete msg;
	return false;
    }

    return true;
}

bool SpiderMsgDeliver::DeliverMessage(size_t cycle, ACE_Message_Block *msg)
{
    assert(cycle < m_Members.size());
    assert(cycle != (size_t)m_self_index);
    ACE_Time_Value nonblock_timeout(0);

    if(m_Members[cycle].client_conn->putq(msg, &nonblock_timeout) == -1){
	return false;
    }

    m_Spider->Counters().incrementCounter(SysCounterTrait::COUNTER_DELIVER_SENT);
    return true;
}

bool SpiderMsgDeliver::DeliverRequestMessage(size_t cycle, const DispatchInfo &dispatch_info, const UrlInfo &urlinfo)
{
    ACE_Message_Block *msg = SpiderMsg::CreateForDispatch(dispatch_info, urlinfo);

    if(!DeliverMessage(cycle, msg)){
	if(errno == EWOULDBLOCK){
	    LOG_WARNING("DROP_OUTPUT_REQUEST_SPIDER_MSG %s to(%lu) OutputMsgQueueFull\n",
		    urlinfo.Uri().ToString().c_str(), cycle);
	}
	else{
	    LOG_WARNING("DROP_OUTPUT_REQUEST_SPIDER_MSG %s to(%lu) ShutDown\n",
		    urlinfo.Uri().ToString().c_str(), cycle);
	}

	delete msg;
	m_Spider->Counters().incrementCounter(SysCounterTrait::COUNTER_DELIVER_DROP_REQUEST_MSG);
	return false;
    }

    return true;
}

bool SpiderMsgDeliver::DeliverFeedbackMessage(size_t cycle, const DispatchInfo &dispatch_info,
	const feedback_header_t &header, const std::string &url)
{
    ACE_Message_Block *msg = SpiderMsg::CreateForFeedbackResult(dispatch_info, header, url);

    if(!DeliverMessage(cycle, msg)){
	if(errno == EWOULDBLOCK){
	    LOG_WARNING("DROP_OUTPUT_FEEDBACK_SPIDER_MSG %s to(%lu) OutputMsgQueueFull\n",
		    url.c_str(), cycle);
	}
	else{
	    LOG_WARNING("DROP_OUTPUT_FEEDBACK_SPIDER_MSG %s to(%lu) ShutDown\n",
		    url.c_str(), cycle);
	}

	delete msg;
	m_Spider->Counters().incrementCounter(SysCounterTrait::COUNTER_DELIVER_DROP_RESULT_MSG);
	return false;
    }

    return true;
}

void SpiderMsgDeliver_Reciver::HandleInputMessage(SpiderMsg *msg)
{
    ACE_Message_Block *msg_block = new ACE_Message_Block((const char *)msg, sizeof(SpiderMsg));
    if(putq(msg_block, NULL) == -1 ){
	if (errno == ESHUTDOWN){
	    LOG_WARNING("DROP_INPUT_SPIDER_MSG %s msg_type(%d) from(%d) ShutingDown\n",
		    msg->url, msg->msg_type, msg->sender_cycle);
	}

	// TODO: drop and leaks
    }
}

SpiderMsgDeliver_Reciver::SpiderMsgDeliver_Reciver(uint16_t port, size_t input_msg_queue_max)
:ACE_Task<ACE_MT_SYNCH>(ACE_Thread_Manager::instance(), NULL),
    m_acceptor(this),
    m_port(port),
    m_input_queue_max(input_msg_queue_max)
{
}

SpiderMsg *SpiderMsgDeliver_Reciver::PopMessage()
{
    static ACE_Time_Value zero_timeout;
    ACE_Message_Block *msg_block = NULL;
    int left = 0;
    if((left = getq(msg_block, &zero_timeout)) == -1){
	return NULL;
    }

    SpiderMsg *msg = (SpiderMsg *)msg_block->base();
    delete msg_block;
    return msg;
}

int SpiderMsgDeliver_Reciver::open()
{
    msg_queue()->high_water_mark(m_input_queue_max);
    return activate(THR_SCOPE_SYSTEM);
}

void SpiderMsgDeliver_Reciver::stop()
{
    m_reactor.end_reactor_event_loop();
}

int SpiderMsgDeliver_Reciver::svc()
{
    ACE_INET_Addr listenaddr(m_port);

    m_reactor.owner(ACE_Thread::self());

    if(m_acceptor.open(listenaddr, &m_reactor, ACE_NONBLOCK) < 0){
	char msg[1024];
	snprintf(msg, sizeof(msg), "%s: Open acceptor on port(%d) failed\n", __FUNCTION__, m_port);
	throw std::runtime_error(msg);
    }

    LOG_NOTICE("SpiderMsgDeliver_Reciver listening on port %d\n", m_port);
    LOG_NOTICE("SpiderMsgDeliver_Reciver reactor start\n");
    if(m_reactor.run_reactor_event_loop() == -1){
	return -1;
    }

    LOG_NOTICE("SpiderMsgDeliver_Reciver reactor exit, errno==%d, %s\n", errno, ACE_OS::strerror(errno));

    return 0;
}
