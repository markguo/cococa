/**
 *    \file   PageFakeMessage.hpp
 *    \brief  Messages between of PageFakeClient and PageFakeServer
 *    \date   04/28/11
 *    \author guoshiwei (guoshiwei@gmail.com)
 */

#ifndef  PAGEFAKEMESSAGE_INC
#define  PAGEFAKEMESSAGE_INC
#include <sasn1/simple_asn1.h>
#include <stddef.h>

/**
 * \brief PageFakeDaemon RPCÏûÏ¢°ü
 */
struct PageFakeMessage
{
    private:
	PageFakeMessage()
	{
	    clear();
	}

	void clear()
	{
	    url = NULL;
	    action = NULL;
	}

    public:
	static PageFakeMessage * CreateFromAsn1Msg(const char * buf, size_t length);

	~PageFakeMessage();

    public:
	char * action;
	char * url;
};

#undef ASN1_MODULE_NAME
#define ASN1_MODULE_NAME PageFakeMessage 
ASN1_DECL_MODULE(ASN1_MODULE_NAME);
ASN1_DECL_MODULE_BODY_BEGIN(ASN1_MODULE_NAME) {
    ASN1_DECL_TYPE(PageFakeMessage);
}
ASN1_DECL_MODULE_BODY_END(ASN1_MODULE_NAME);

#endif   /* ----- #ifndef PAGEFAKEMESSAGE_INC  ----- */
