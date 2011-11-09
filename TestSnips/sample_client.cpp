/*
 * =====================================================================================
 *
 *       Filename:  sample_client.cpp
 *
 *    Description:  A sample showing how to use the libsscCore
 *
 *        Version:  1.0
 *        Created:  12/30/2009 10:56:52 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Guo Shiwei (), guoshiwei@sohu-rd.com
 *        Company:  sohu
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>

#include <stdexcept>

#include "debug.h"
#include "TSSConsumerCore.hpp"

bool g_exit = false;

void handleSigExit(int)
{
    g_exit = true;
}

void dump_result(const spiderservice::client::Result &r)
{
    // Attributs
    printf("Attributs: =======================================\n");
#define PRINT_ATTR_STR(f) printf("\t" #f ": %s\n", r.f());
#define PRINT_ATTR_INT(f) printf("\t" #f ": %d\n", (int)r.f());
    PRINT_ATTR_STR(url);
    PRINT_ATTR_STR(batchID);
    PRINT_ATTR_STR(subbatch);
    PRINT_ATTR_STR(attach);
    PRINT_ATTR_STR(type);
    PRINT_ATTR_STR(ip_address);
    PRINT_ATTR_STR(user_agent);
    PRINT_ATTR_INT(isSucceed);
    PRINT_ATTR_STR(error_reason);
    PRINT_ATTR_STR(start_fetch_time);
    PRINT_ATTR_STR(end_fetch_time);
    PRINT_ATTR_INT(rediect_count);
    PRINT_ATTR_STR(final_redirect);
    PRINT_ATTR_INT(resp_body_original_len);
    PRINT_ATTR_INT(resp_body_len);
#undef PRINT_ATTR_INT
#undef PRINT_ATTR_STR

    // Meta Headers
    printf("\nMeta Headers: ==========================================\n");
    size_t n = r.getExtraMetaHeaderSize();
    for(size_t i = 0; i < n; ++i){
        printf("\t%s: %s\n", r.getExtraMetaHeaderName(i),
                r.getExtraMetaHeaderValue(i));
    }

    // Http Hreaders
    printf("\nHttp Headers: ==========================================\n");
    n = (size_t)r.resp_header_size();
    for(size_t i = 0; i < n; ++i){
        printf("\t%s\n", r.getRespHeaderItem((int)i));
    }
}

int main(int argc, char **argv)
{
    struct sigaction act;
    bzero(&act, sizeof(act));
    act.sa_handler = handleSigExit;
    if(sigaction(SIGTERM, &act, NULL) < 0
            ||sigaction(SIGINT, &act, NULL) < 0
            ||sigaction(SIGUSR1, &act, NULL) < 0
            ){
        throw std::runtime_error("registor SIGTERM handler failed");
    }

    spiderservice::client::TSSConsumerCore core(atoi(argv[1]), 20);
    if(core.start() < 0){
        SSLOG_ERROR("Start TSSConsumerCore failed");
        exit(EXIT_FAILURE);
    }

    spiderservice::client::Result result;
    struct timeval timeout = {1, 0};
    while(!g_exit){
        if(core.getResult(result, &timeout) == 0){
            SSLOG_INFO("Got result of '%s'",
                    result.url());
            dump_result(result);
        }
    }

    SSLOG_INFO("EXITING ...");
    core.stop();
    while(core.getResult(result, &timeout) == 0){
        SSLOG_INFO("Got result of '%s'",
                result.url());
    }

    SSLOG_INFO("EXITED");
    return 0;
}
