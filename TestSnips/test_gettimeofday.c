/*
 * =====================================================================================
 *
 *       Filename:  test_gettimeofday.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2010��12��15�� 15ʱ42��47��
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Guo Shiwei (), guoshiwei@sohu-rd.com
 *        Company:  sohu
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <sys/time.h>
int main()
{
        struct timeval now;
        gettimeofday(&now, NULL);
        printf("tv_sec=%lu tv_usec=%lu\n", now.tv_sec, now.tv_usec);
        return 0;
}
