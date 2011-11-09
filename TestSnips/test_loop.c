/*
 * =====================================================================================
 *
 *       Filename:  test_loop.c
 *
 *    Description:  test_loop time
 *
 *        Version:  1.0
 *        Created:  2010年04月22日 11时52分26秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Guo Shiwei (), guoshiwei@sohu-rd.com
 *        Company:  sohu
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char **argv)
{
        int num = 5000000;
        int i = 0;
        int j = 0;

        char * s1 = "aaaaaaaaaaaaaaaaaaaaa";
        char * s2 = "bbbbbbbbbbbbb";
        for(i = 0; i < num; ++ i){
                for (j = i; j < num; ++j){
        
                        strcmp(s1, s2);
                }

                if (i % 100 == 0){
                        time_t t = time(NULL);
                        printf("[%s] %d\n", ctime(&t), i);
                }

        }

        return 0;
}
