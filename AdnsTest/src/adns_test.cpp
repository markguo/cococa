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

static void failure_errno(const char *what, int errnoval) 
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

    exit(2);
}

static void dumptype(adns_status ri, const char *rrtype_name, const char *fmtname) {
    fprintf(stdout, "%s(%s)%s%s",
	    (!ri && rrtype_name) ? rrtype_name : "?",
	    ri ? "?" : (fmtname ? fmtname : "-"),
	    ri ? " " : "",
	    ri ? adns_strerror(ri) : "");
}

static void failure_status(const char *what, adns_status st) {
    fprintf(stderr,"adns failure: %s: %s\n",what,adns_strerror(st));
    exit(2);
}

/**
 * Submit DNS query of A type
 */
static bool __adns_submit_A(adns_state ads, const char * domain, adns_query &one_query)
{
    adns_status ri;
    adns_rrtype rrtype = adns_r_a;
    const char * rrtype_name = NULL;
    const char * fmtname = NULL;

    int r = adns_submit(ads, domain, rrtype, adns_qf_none, NULL, &one_query);
    if (r) {
	failure_errno("submit",r);
	return false;
    }

    ri = adns_rr_info(rrtype, &rrtype_name, &fmtname,0, 0,0);
    fprintf(stdout, "%s", domain);
    putc(' ',stdout);
    dumptype(ri, rrtype_name, fmtname);
    fprintf(stdout," submitted\n");
    return true;
}

static bool __adns_handle_answer(adns_state ads, const adns_answer *ans, const char *domain, const struct timeval &now)
{
    int len;
    adns_status ri;
    const char * rrtype_name = NULL;
    const char * fmtname = NULL;

    ri = adns_rr_info(ans->type, &rrtype_name, &fmtname, &len, 0,0);
    fprintf(stdout, "%s flags %d type ",domain, adns_qf_none);

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
	    if (ri) failure_status("info",ri);
	    fprintf(stdout," %s\n",show);
	    free(show);
	}
    }

    if(ans->status == adns_s_prohibitedcname){
	__adns_submit_A(ads, ans->cname, one_query);
	return true;
    }


    return false;
}

int main(int argc, char * argv[])
{
    adns_state ads;

    adns_initflags adns_if = (adns_initflags)(adns_if_debug|adns_if_noautosys);
    int r = adns_init(&ads, adns_if, NULL);

    if(r)
	failure_errno("adns_init", r);

    const char * domain = "www.sohu.com";

    if(!__adns_submit_A(ads, domain, one_query))
	return 1;

    while(1){
	adns_answer *ans;
	struct timeval now;
	gettimeofday(&now,0);
	r = adns_wait(ads, &one_query, &ans, NULL);
	if (r) failure_errno("wait/check",r);
	if(!__adns_handle_answer(ads, ans, domain, now))
	    break;
    }



}
