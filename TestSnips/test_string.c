/*
 * =====================================================================================
 *
 *       Filename:  test_string.c
 *
 *    Description:  Test string methods
 *
 *        Version:  1.0
 *        Created:  2010年05月18日 14时53分42秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Guo Shiwei (), guoshiwei@sohu-rd.com
 *        Company:  sohu
 *
 * =====================================================================================
 */

#include <string.h>
#include <stdio.h>

const char *prog_name = NULL;

void usage()
{
        printf("usage: %s string\n", prog_name);
}

int main(int argc, char **argv)
{
        if (argc != 2){
                usage();
                return 1;
        }

	fprintf(stderr, "%.*s\n", 2, argv[1]);

        const char *digits = "0123456789";
        const char *str = argv[1];
        size_t len = strlen(argv[1]);
        size_t start = strcspn(argv[1], digits);

        if (start == len){
                printf("no digits found in [%s]\n", str);
                return 1;
        }
        else if(start < len){
                printf("Digits start: [%s]\n", str + start);
                size_t end = strspn(str + start, digits);
                if (end + start == len){
                        printf("num is [%s]\n", str + start);
                }
                else if (end + start < len ){
                        char num[1024];
                        strncpy(num, str + start, end);
                        num[end] = '\0';
                        printf("num is [%s]\n", num);
                }
                else{
                        printf("Unknow strspn return: %lu\n", end);
                }
        }
        else{
                printf("Unknow strcspn return: %lu\n", start);
        }

        return 0;
}
