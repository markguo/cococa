/**
 *    \file   adns_test.cpp
 *    \brief  
 *    \date   2011Äê08ÔÂ04ÈÕ
 *    \author guoshiwei (guoshiwei@gmail.com)
 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <assert.h>
#include <sys/time.h>

#include <adns.h>

adns_query one_query;

static void __failure_errno(const char *what, int errnoval) 
{
    switch (errnoval) {
#define CE(e) \
	case e: fprintf(stderr,"adns failure: %s: errno=" #e "\n",what); break
		CE(EINVAL);
		CE(EINTR);
		CE(ESRCH);
		CE(EAGAIN);
		CE(ENOSYS);
		CE(ERANGE);
#undef CE
	default: fprintf(stderr,"adns failure: %s: errno=%d\n",what,errnoval); break;
    }
}

static void dumptype(adns_status ri, const char *rrtype_name, const char *fmtname) {
    fprintf(stdout, "%s(%s)%s%s",
	    (!ri && rrtype_name) ? rrtype_name : "?",
	    ri ? "?" : (fmtname ? fmtname : "-"),
	    ri ? " " : "",
	    ri ? adns_strerror(ri) : "");
}

static void __adns_logcallback(adns_state ads, void *logfndata,
				const char *fmt, va_list al)
{
    vfprintf(stderr, fmt, al);
}

class Adns;
struct AdnsQuery
{
    public:

    private:
	friend class Adns;
	adns_query query_;
	bool done_;
};

class Adns
{
    public:
	Adns(){}
	~Adns();

	bool init();

	/**
	 * Submit A type DNS query.
	 */
	bool submit(const char *domain, AdnsQuery *p_query);

	bool poll(AdnsQuery ** finished_query_r);

    private:
	bool handle_answer(const adns_answer *ans, AdnsQuery *p_query, const struct timeval &now);
	bool submit_adns_query(const char *domain, AdnsQuery *p_query);

    private:
	adns_state ads_;
};

Adns::~Adns()
{
    if(ads_)
	adns_finish(ads_);
}

bool Adns::init()
{
    adns_initflags adns_if = (adns_initflags)(adns_if_noautosys);
    int r = adns_init_logfn(&ads_, adns_if, NULL,
	    __adns_logcallback, NULL);

    if(r){
	__failure_errno("adns_init", r);
	return false;
    }

    return true;
}

bool Adns::submit_adns_query(const char *domain, AdnsQuery *p_query)
{
    int r = adns_submit(ads_, domain, adns_r_a, adns_qf_owner, p_query, &p_query->query_);
    if (r) {
	__failure_errno("submit",r);
	return false;
    }

    fprintf(stderr, "%s submitted\n", domain);
    p_query->done_ = false;
    return true;
}

bool Adns::submit(const char *domain, AdnsQuery *p_query)
{
    return submit_adns_query(domain, p_query);
}

bool Adns::poll(AdnsQuery ** finished_query_r)
{
    adns_answer *ans;
    struct timeval now;
    gettimeofday(&now,0);

    adns_query finished_adns_query = NULL;

    void * context = NULL;
    int r = adns_wait(ads_, &finished_adns_query, &ans, &context);
    if (r) __failure_errno("wait/check",r);

    AdnsQuery *finished_query = (AdnsQuery *)context;
    assert(finished_query->query_ == finished_adns_query);

    handle_answer(ans, finished_query, now);

    if(finished_query->done_){
	if(finished_query_r)
	    *finished_query_r = finished_query;

	return false;
    }

    return true;
}

bool Adns::handle_answer(const adns_answer *ans, AdnsQuery *p_query, const struct timeval &now)
{
    int len;
    adns_status ri;
    const char * rrtype_name = NULL;
    const char * fmtname = NULL;

    ri = adns_rr_info(ans->type, &rrtype_name, &fmtname, &len, 0,0);
    fprintf(stdout, "%s flags %d type ", ans->owner, adns_qf_none);

    dumptype(ri, rrtype_name, fmtname);
    fprintf(stdout, " %s; nrrs=%d; cname=%s; owner=%s; ttl=%ld\n",
	    false ? adns_errabbrev(ans->status)
	    : adns_strerror(ans->status),
	    ans->nrrs,
	    ans->cname ? ans->cname : "$",
	    ans->owner ? ans->owner : "$",
	    (long)ans->expires - (long)now.tv_sec);

    if (ans->nrrs) {
	assert(!ri);
	char *show;
	for (int i=0; i<ans->nrrs; i++) {
	    ri = adns_rr_info(ans->type, 0,0,0, ans->rrs.bytes + i*len, &show);
	    if (ri){
		fprintf(stderr,"adns failure: %s: %s\n", "adns_rr_info", adns_strerror(ri));
		assert(false);
	    }

	    fprintf(stdout," %s\n",show);
	    free(show);
	}
    }

    if(ans->status == adns_s_prohibitedcname){
	return submit_adns_query(ans->cname, p_query);
    }

    p_query->done_ = true;
    return true;
}

/*-----------------------------------------------------------------------------
 *  
 *-----------------------------------------------------------------------------*/

int main(int argc, char * argv[])
{
    const char * domain = "www.sohu.com";

    Adns adns;
    if(!adns.init())
	return 1;

    AdnsQuery one_query;
    if(!adns.submit(domain, &one_query))
	return 1;

    while(1){
	AdnsQuery * finished_query = NULL;
	if(!adns.poll(&finished_query))
	    break;
    }

    return 0;
}
