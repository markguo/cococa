/**
 *    \file   PageFakeClient.hpp
 *    \brief  Client of PageFakeServer
 *    \date   04/28/11
 *    \author guoshiwei (guoshiwei@gmail.com)
 */

#ifndef  PAGEFAKECLIENT_INC
#define  PAGEFAKECLIENT_INC
#include <sasn1/simple_asn1.h>

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
#include <ace/Connector.h>
#include <ace/INET_Addr.h>
#include <ace/Reactor.h>
#include <ace/Svc_Handler.h>
#include <ace/SOCK_Acceptor.h>
#include <ace/SOCK_Connector.h>

/**
 * Send and recv with remote server, in block mode
 */
class TRemoteHandle{
    public:
	TRemoteHandle(const char *ip, unsigned short port);
	TRemoteHandle(const char * address);
	~TRemoteHandle();

	int open();

	int close()
	{
	    m_connected = false;
	    return m_peer.close();
	}

	template<typename ASN1_MSG_T>
	    SpiderServiceErrno send(const char *cmd_name, const ASN1_MSG_T *msg);

	//      template<>
	//      SpiderServiceErrno send<void>(const char *cmd_name, void * dummy_msg = NULL);

	template<typename ASN1_MSG_T>
	    SpiderServiceErrno recv(ASN1_MSG_T *msg);

	const std::string &ip(){return m_ip;}
	unsigned short port(){return m_port;}
	const std::string &getRemoteAddr() const {return m_remoteAddr_str;}

	void noSIGPIPE();

    private:
	int send_i(ACE_Message_Block *header_buf, ACE_Message_Block *body_buf);

	/// Return number of bytes recieved
	int recv_i(ACE_Message_Block *recvbuf);

    private:
	std::string m_ip;
	unsigned short m_port;
	std::string m_remoteAddr_str;
	ACE_INET_Addr m_remoteAddr;

	ACE_Message_Block m_reqHeader;
	ACE_Message_Block m_reqBody;

	ACE_SOCK_Connector m_connector;
	ACE_SOCK_Stream m_peer;
	bool m_connected;
};

/*-----------------------------------------------------------------------------
 *  Implement of template methods.
 *-----------------------------------------------------------------------------*/

/// explicit specialization of send
template<>
SpiderServiceErrno TRemoteHandle::send<void>(const char *cmd_name, const void * dummy_msg);

    template<typename ASN1_MSG_T>
SpiderServiceErrno TRemoteHandle::send(const char *cmd_name, const ASN1_MSG_T *msg)
{
    m_reqHeader.reset();
    m_reqBody.reset();

    int header_len = 0;
    if(msg){
	// encode

	processor::encodeCmd(*msg, &m_reqBody);


	header_len = snprintf(m_reqHeader.wr_ptr(), m_reqHeader.space(),
		REQ_POST_HEADER_TPL, cmd_name,
		static_cast<unsigned int>(m_reqBody.length()));
    }
    else{
	header_len = snprintf(m_reqHeader.wr_ptr(), m_reqHeader.space(),
		REQ_GET_HEADER_TPL, cmd_name);
    }

    m_reqHeader.wr_ptr(header_len);

    int ret = send_i(&m_reqHeader, &m_reqBody); 
    if( ret < 0 ){
	SSLOG_ERROR("%s: send %s faild, errno == %d %s", __FUNCTION__,
		cmd_name, errno, strerror(errno));
	close();
	return SS_NETWORK_ERROR;
    }

    return SS_OK;
}

#endif   /* ----- #ifndef PAGEFAKECLIENT_INC  ----- */

