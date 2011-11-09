/**
 *    \file   test_memleak.c
 *    \brief  
 *    \date   2011Äê11ÔÂ04ÈÕ
 *    \author guoshiwei (guoshiwei@gmail.com)
 */

#include <stdlib.h>
#include <assert.h>
int main(int argc, char *argv[])
{

    assert(0);

    int i = 0;
    for(i = 0; i < 3; ++i){
	char *p1 = malloc(25);
	p1 = NULL;
    }

    char *p2 = malloc(30);
    p2 = NULL;
}
