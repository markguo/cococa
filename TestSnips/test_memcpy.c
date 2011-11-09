/*
 * =====================================================================================
 *
 *       Filename:  test_memcpy.c
 *
 *    Description:  test memcpy time
 *
 *        Version:  1.0
 *        Created:  12/29/2009 06:39:18 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Guo Shiwei (), guoshiwei@sohu-rd.com
 *        Company:  sohu
 *
 * =====================================================================================
 */

#include <string.h>
#include <stdlib.h>

#define M (1024 *1024)

int main(int argc, char **argv)
{

    size_t size = atoi(argv[1]) * M;
    char *src = (char *) malloc(size);
    char *dst = (char *) malloc(size);

    memcpy(dst, src, size);
    free(src);
    free(dst);
}
