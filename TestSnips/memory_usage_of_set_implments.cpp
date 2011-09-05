/**
 *    \file   memory_usage_of_set_implments.cpp
 *    \brief  Compare memory effiction in various set implement
 *    \date   2011Äê09ÔÂ06ÈÕ
 *    \author guoshiwei (guoshiwei@gmail.com)
 */

#include <stdio.h>
#include <stdlib.h>
#include <set>

enum ImplmentType
{
    IMPL_RAW_RBTREE,
    IMPL_STD_SET,
    IMPL_STD_UNORDERED_SET,
    IMPL_GOOGLE_SPARSEHASH
};

int test(ImplmentType type, size_t item_num)
{
    using namespace std;

    set<int> int_set;
    for(size_t i ; i < item_num; ++i){
	int_set.insert(i);
    }
}

int main(int argc, char *argv[])
{
    if(argc != 2){
	printf("usage: memory_usage_of_set_implments item_num\n");
	return 1;
    }

    int item_num = atoi(argv[1]);

    test(IMPL_STD_SET, item_num);

    printf("press any key to continue\n");
    getc(stdin);

    return 0;
}
