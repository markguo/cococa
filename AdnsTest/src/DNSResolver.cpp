/**
 *    \file   DNSResolver.cpp
 *    \brief  
 *    \date   2011Äê08ÔÂ05ÈÕ
 *    \author guoshiwei (guoshiwei@gmail.com)
 */

#include "DNSResolver.hpp"

class DNSResolver::DNSResolver()
    :padding_req_num_(0),
    req_timeout_(0)
{
}


bool DNSResolver::submit(std::string &domain, void *user_data)
{
    DNSResult *result = new DNSResult;
    result->domain.swap(domain);
    result->user_data = user_data;

    adns_query qu; // We do not need to store this handle indeed.
    int r = adns_submit(ads_, result->domain.c_str(), adns_r_a, adns_qf_none, result, &qu);
    if (r) {
	__failure_errno("submit",r);
	return false;
    }

    fprintf(stderr, "%s submitted\n", result->domain.c_str());
    result->done_ = false;
}


void poll(struct timeval *timeout)
{
    adns_query qu;
    void * context = NULL;
    struct timeval now;
    gettimeofday(&now, NULL);

    for (adns_forallqueries_begin(ads_);
	 (qu = adns_forallqueries_next(ads_, &context));){

      DNSResult *result = static_cast<DNSResult*>(context);
      assert(!result->done_);
    }

    adns_answer *ans;
    int r = adns_wait(ads_, &qu, &ans, &context);
    if (r) __failure_errno("wait/check",r);

    DNSResult *result = static_cast<DNSResult*>(context);

    int len;
    adns_status ri;
    const char * rrtype_name = NULL;
    const char * fmtname = NULL;

    if(ans->status == adns_s_prohibitedcname){
	adns_query qu; // We do not need to store this handle indeed.
	int r = adns_submit(ads_, result->domain.c_str(), adns_r_a, adns_qf_none, result, &qu);
	if (r) {
	    __failure_errno("submit",r);
	    assert(false);
	}

	fprintf(stderr, "%s submitted\n", result->domain.c_str());
	result->done_ = false;
	return;
    }
    else if (ans->nrrs) {
	assert(!ri);
	char *show;
	for (int i=0; i<ans->nrrs; i++) {
	    // TODO: convert ans->rrs.bytes to addrinfo
	    ri = adns_rr_info(ans->type, 0,0,0, ans->rrs.bytes + i*len, &show);
	    if (ri){
		fprintf(stderr,"adns failure: %s: %s\n", "adns_rr_info", adns_strerror(ri));
		assert(false);
	    }

	    fprintf(stdout," %s\n",show);
	    free(show);
	}

	result->done_ = true;
	result->error = RE_OK;
	cb_(result);
    }
    else{
	// NO addr found
	result->error = RE_NOTFOUND;
	result->done_ = true;
	cb_(result);
    }
}

void DNSResolver::handle_answer(const adns_answer *ans, DNSResult *result, const str
