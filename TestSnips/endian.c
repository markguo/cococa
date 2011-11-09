/**
 *    \file   endian.c
 *    \brief  
 *    \date   2011Äê10ÔÂ09ÈÕ
 *    \author guoshiwei (guoshiwei@gmail.com)
 */

#include <stdio.h>

int main(int argc, char **argv)
{
    int value = 0;
    char *p = (char *)&value;
    p[0] = 1;

    printf("%d\n", value);
}
