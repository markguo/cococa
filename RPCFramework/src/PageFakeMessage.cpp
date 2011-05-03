/**
 *    \file   PageFakeMessage.cpp
 *    \brief  
 *    \date   04/28/11
 *    \author guoshiwei (guoshiwei@gmail.com)
 */

#include <ace/Message_Queue.h>
#include "PageFakeMessage.hpp"

ASN1_IMPL_MODULE(ASN1_MODULE_NAME, V_ASN1_TP_IMPLICIT_TAGS);

ASN1_IMPL_MODULE_BODY_BEGIN(ASN1_MODULE_NAME) {
    ASN1_BIND_SEQUENCE_BEGIN(PageFakeMessage){
	ASN1_BIND_FIELD_SIMPLE(action),
	ASN1_BIND_FIELD_SIMPLE(url),
	ASN1_BIND_SEQUENCE_NULL_EXTENSION(),
    } ASN1_BIND_SEQUENCE_END(PageFakeMessage);

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
PageFakeMessage * PageFakeMessage::CreateFromAsn1Msg(const char * buf, size_t length)
{
    PageFakeMessage *msg = new PageFakeMessage;
    if(!decodeCmd(*msg, buf, length)){
	delete msg;
	return NULL;
    }

    return msg;
}


PageFakeMessage::~PageFakeMessage()
{
    asn1::asn1_destruct(Asn1Allocator(), this);
}
