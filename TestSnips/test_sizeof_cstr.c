/*
 * =====================================================================================
 *
 *       Filename:  test_sizeof_cstr.c
 *
 *    Description:  i
 *
 *        Version:  1.0
 *        Created:  2010年11月15日 15时21分43秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Guo Shiwei (), guoshiwei@sohu-rd.com
 *        Company:  sohu
 *
 * =====================================================================================
 */

#include <stdio.h>

struct A{
    union {
	int b;
	int c;
	char d;
    };
    char a;
};

int main(int argc, char *argv)
{
        const char * TEST_STR = "搜狗问答";
        printf("sizeof(long long) == %lu sizeof(%s) == %lu\n",
                        sizeof(long long),
                        TEST_STR,
                        sizeof(TEST_STR));

	printf("sizeof(struct A) == %lu\n", sizeof(struct A));
        return 0;
}
