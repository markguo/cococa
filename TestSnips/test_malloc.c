/*
 * =====================================================================================
 *
 *       Filename:  test_malloc.c
 *
 *    Description:  See the layout of malloced memory.
 *
 *        Version:  1.0
 *        Created:  12/03/2009 02:42:08 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Guo Shiwei (), guoshiwei@sohu-rd.com
 *        Company:  sohu
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>

void makeCoreDump()
{
    int i;
    char * mem = (char*)malloc(8);
    char *mem2 = (char *)malloc(16);
    char *mem3 = NULL;
    char *mem4 = NULL;
    for(i = 0; i < 8; ++i){
        mem[i] = 'A';
    }
    for(i = 0; i < 16; ++i){
        mem2[i] = 'B';
    }

    free(mem);

    mem3 = (char *) malloc(57);

    for(i = 0; i < 57; ++i){
        mem3[i] = 0xAA;
    }
    mem4 = (char *) malloc(32);
    for(i = 0; i < 32; ++i){
        mem4[i] = 0x55;
    }


    printf("addr of mem == 0x%x\n", mem);
    // make a coredump
    abort(); 

}

void testAllocate(size_t alloc_size, size_t alloc_obj_num)
{
    void * dummy ;
    size_t i = 0;
    for( i = 0; i < alloc_obj_num; ++i){
        // Don't worry, let it leak ...
        dummy = malloc(alloc_size);
    }

}

int main(int argc, char **argv)
{
    int alloc_obj_num, alloc_size;
    if(argc == 1){
        makeCoreDump();
    }
    else if(argc == 3){
        alloc_size = atoi(argv[1]);
        alloc_obj_num = atoi(argv[2]);

        testAllocate(alloc_size, alloc_obj_num);
        printf("malloced %lu pieces of %lu size mem\n", 
                alloc_obj_num, alloc_size);
        while(1){
            sleep(10);
        }
    }

    return 0;
} 
    
