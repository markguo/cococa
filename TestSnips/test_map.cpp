/**
 *    \file   test_map.cpp
 *    \brief  
 *    \date   2011Äê09ÔÂ01ÈÕ
 *    \author guoshiwei (guoshiwei@gmail.com)
 */

#include <map>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char **argv)
{
    int item_num = atoi(argv[1]);
    map<int, int> int_map;
    for(int i= 0; i < item_num; ++i){
	int_map.insert(make_pair(i, i));
    }

    for(map<int, int>::iterator it = int_map.begin();
	    it != int_map.end(); ++it){
	// no opt
    }

    return 0;
}
