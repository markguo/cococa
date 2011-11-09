/*
 * =====================================================================================
 *
 *       Filename:  test_cocurrent_add.c
 *
 *    Description:  Test whether the '+' operation on int is a atomic operation
 *
 *        Version:  1.0
 *        Created:  10/28/2009 05:07:02 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Guo Shiwei (), guoshiwei@sohu-rd.com
 *        Company:  sohu
 *
 * =====================================================================================
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

long int g_i = 0;

int loop_count = 10000;
int thread_num = 8;

void * add_thread(void * param)
{
    int i = 0;
    for(i = 0; i < loop_count; ++i){
        g_i += 1;
    }

    return NULL;
}

int main(int argc, char **argv)
{
    int i = 0;
    pthread_t * thrs = NULL;
    if(argc > 2){
        loop_count = atoi(argv[1]);
        thread_num = atoi(argv[2]);
    }

    printf("loop_count == %d, thread_num == %d\n", 
            loop_count, thread_num);
    if(loop_count <= 0 || thread_num <= 0){
        fprintf(stderr, "bad param\n");
        exit(EXIT_FAILURE);
    }

    thrs = (pthread_t *) malloc(sizeof(pthread_t) * thread_num);
    if(!thrs){
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    printf("start ... \n");
    for( i = 0; i < thread_num; ++i){
        if(pthread_create(&thrs[i], NULL, add_thread, NULL) < 0){
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    printf("end ... \n");
    for( i = 0; i < thread_num; ++i){
        if(pthread_join(thrs[i], NULL) < 0){
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    printf("final g_i == %d, g_i should be == %d, %s\n",
            g_i, loop_count * thread_num, (g_i == loop_count * thread_num) ? "atomic" : "none atomic");
}
