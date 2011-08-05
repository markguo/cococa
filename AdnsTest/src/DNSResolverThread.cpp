/**
 *    \file   DNSResolverThread.cpp
 *    \brief  
 *    \date   2011Äê08ÔÂ05ÈÕ
 *    \author guoshiwei (guoshiwei@gmail.com)
 */

#include "DNSResolverThread.hpp"

void DNSResolverThread::run()
{
    while(!stop_){
	while(!padding_req_queue_.empty()){
	    Req &req = padding_req_queue_.head();
	    if(!resolver_.submit(req.domain, req.user_data))
		break;

	    padding_req_queue_.pop();
	    padding_req_num_ --;
	}

	struct timeval timeout = {0, 500};
	resolver_.poll(&timeout);
    }

    while(!padding_req_queue_.empty()){
	Req &req = padding_req_queue_.head();

	DNSResult *result = new DNSResult;
	result->domain.swap(req.domain);
	result->user_data = req.user_data;

	result_queue_.push_back(result);
	padding_req_queue_.pop();
	padding_req_num_ --;
    }
}
