/*
 * =====================================================================================
 *
 *       Filename:  test_cframe.c
 *
 *    Description:  See structure of function call frame of c.
 *
 *        Version:  1.0
 *        Created:  12/02/2009 02:14:09 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Guo Shiwei (), guoshiwei@sohu-rd.com
 *        Company:  sohu
 *
 * =====================================================================================
 */
#include <stdio.h>

int function(int a, int b, int c)
{
    char buffer[14];
    int     sum;
    int i = 0;
    sum = a + b + c;

    for (i = 0; i < 14; ++i){
        buffer[i] = 5;
    }
    return sum;
}

void foo(int *p)
{

}

int main()
{
    int i = 0;
    int * pi = &i;
    int * pi2 = pi;

    foo(pi);
    int &ref_i = i;
    foo(&ref_i);

    return 0;
}
