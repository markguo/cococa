/*
 * =====================================================================================
 *
 *       Filename:  test_ace.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2011年01月27日 20时24分30秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Guo Shiwei (), guoshiwei@sohu-rd.com
 *        Company:  sohu
 *
 * =====================================================================================
 */

#include <ace/Reactor.h>
#include <iconv.h>
#include <string>

std::string iconv_gbk_utf16(const char *from)
{
    iconv_t cd = iconv_open("utf16", "ascii");
    if(cd == (iconv_t)-1){
	perror("iconv_open fail: ");
	exit(1);
    }

    char *from_buf = strdup(from);
    char *inbuf = from_buf;
    size_t inbytesleft = strlen(from);
    size_t outbytesleft = 4 * inbytesleft;
    char *to_buf = (char *)malloc(outbytesleft);
    char *outbuf = to_buf;
    while(inbytesleft){
	fprintf(stderr, "%s %zd %s %zd\n",
		inbuf, inbytesleft,
		outbuf, outbytesleft);

	size_t n = iconv(cd, &inbuf, &inbytesleft,
		&outbuf, &outbytesleft);
	if(n == (size_t)-1){
	    perror("iconv fail:");
	    exit(1);
	}
    }
    iconv_close(cd);
    free(from_buf);
    free(to_buf);
    std::string ret(to_buf, outbuf - to_buf);
    fprintf(stderr, "ICONV: ret.length:%zd\n", ret.length());
    return ret;
}

int main()
{
    // ACE_Reactor reactor;
    // ACE_Time_Value timeout(1, 0);
    // while(reactor.run_reactor_event_loop(timeout) != -1){
    //     time_t now = time(NULL);
    //     printf("timeout %s", ctime(&now));
    //     timeout.set(1, 0);
    // }

    std::string utf16_lf = iconv_gbk_utf16("\n");
    printf("%.*s", (int)utf16_lf.length(), utf16_lf.data());
    return 0;
}
