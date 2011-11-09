/*
 * =====================================================================================
 *
 *       Filename:  test_strcmp.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/21/2010 10:35:42 AM
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

int main(int argc, char **argv)
{
    if(argc != 3){
        printf("usage: %s str1 str2\n", argv[0]);
        return 0;
    }

    int ret = strcmp(argv[1], argv[2]);
    printf("%s %s %s\n", argv[1],
            ret == 0 ? "=="
            : (ret > 0 ? ">" : "<"),
            argv[2]);
    return 0;
}
