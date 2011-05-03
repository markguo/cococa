#ifndef  SPIDERMSGDELIVER_INC
#define  SPIDERMSGDELIVER_INC

#include <vector>
#include <string>
#include <boost/shared_ptr.hpp>

#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stddef.h>
#include <stdint.h>

// Third party libs
#include <ace/Synch.h>
#include <ace/Message_Queue.h>
#include <ace/Acceptor.h>
#include <ace/INET_Addr.h>
#include <ace/Reactor.h>
#include <ace/Svc_Handler.h>
#include <ace/SOCK_Acceptor.h>

class MyAcceptor;
class PageFakeServer;
class PageFakeMessage;

class TServiceConnHandler: public ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_MT_SYNCH>
{
    private:
	enum TAppState {
	    APP_READ_HEADER,
	    APP_READ_BODY,
	};

    public:
	virtual int open(void *);
	virtual int handle_close(ACE_HANDLE handle, ACE_Reactor_Mask close_mask);
	virtual int handle_input(ACE_HANDLE fd = ACE_INVALID_HANDLE);

	std::string getPeerAddr(){return m_peerAddr;}

    private:
	typedef ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_MT_SYNCH> supper;
	void reserve_inbuffer(int require);
	void process_message(const char *buf, size_t length);

    private:
	MyAcceptor * m_acceptor;
	PageFakeServer *m_reciver;
	ACE_INET_Addr m_inetRemoteAddr;
	std::string m_peerAddr;

	ACE_Message_Block m_inbuf;

	TAppState m_appState;
	size_t m_bodylen;
	size_t m_readLeft;
};

typedef ACE_Acceptor<TServiceConnHandler, ACE_SOCK_ACCEPTOR> MyAcceptorBase;
class MyAcceptor: public MyAcceptorBase
{
    public:
	MyAcceptor(PageFakeServer *reciver)
	    :m_reciver(reciver)
	{}

	PageFakeServer *m_reciver;
};

class PageFakeServer: public ACE_Task<ACE_MT_SYNCH> {

    public:
	PageFakeServer(uint16_t port, size_t input_msg_queue_max);

	PageFakeMessage *PopMessage();

	int open();
	void stop();
	int svc();

	void HandleInputMessage(PageFakeMessage *msg);

    private:
	ACE_Reactor m_reactor;
	MyAcceptor m_acceptor;
	int m_port;
	size_t m_input_queue_max;
};

#endif   /* ----- #ifndef SPIDERMSGDELIVER_INC  ----- */
