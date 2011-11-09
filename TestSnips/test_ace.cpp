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
int main()
{
    ACE_Reactor reactor;
    ACE_Time_Value timeout(1, 0);
    while(reactor.run_reactor_event_loop(timeout) != -1){
	time_t now = time(NULL);
	printf("timeout %s", ctime(&now));
	timeout.set(1, 0);
    }

    return 0;
}
