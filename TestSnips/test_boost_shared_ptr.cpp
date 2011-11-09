/*
 * =====================================================================================
 *
 *       Filename:  test_boost_shared_ptr.cpp
 *
 *    Description:  Test boost::shared_ptr copy performace
 *
 *        Version:  1.0
 *        Created:  01/27/2010 08:28:16 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Guo Shiwei (), guoshiwei@sohu-rd.com
 *        Company:  sohu
 *
 * =====================================================================================
 */

#include <boost/shared_ptr.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

boost::shared_ptr<int> p_obj(new int(4));
pthread_rwlock_t obj_protect_rwlock;

void * reader_thread(void *)
{
        while(1){
                pthread_rwlock_rdlock(&obj_protect_rwlock);
                boost::shared_ptr<int> copy_ptr = p_obj;
                pthread_rwlock_unlock(&obj_protect_rwlock);
                //fprintf(stderr, "read %d...\n", *copy_ptr);
        }
        return NULL;
}
void * writer_thread(void *)
{
        while(1){
                pthread_rwlock_wrlock(&obj_protect_rwlock);
                boost::shared_ptr<int> new_obj(new int(3));
                p_obj = new_obj;
                pthread_rwlock_unlock(&obj_protect_rwlock);
                //fprintf(stderr, "write %d...\n", *p_obj);
        }

        return NULL;
}

struct A{
        int xx;
        char * test_a;
        A(){
                test_a = (char *) malloc(3);
        }
        ~A(){
                printf("destruct A\n");
                free(test_a);
        }
};

struct B{
        A a;
        char * test;

        B(){
                //test = (char *)malloc(3);
        }
        ~B(){
                printf("destruct B\n");
                //free(test);
        }
};

int main(int argc, char **argv)
{
    if(argc != 2){
        printf("usage: %s loop_num\n", argv[0]);
        return -1;
    }

    pthread_rwlock_init(&obj_protect_rwlock, NULL);
    pthread_t reader_threadid, writer_threadid;
    pthread_create(&reader_threadid, NULL, reader_thread, NULL);
    pthread_create(&writer_threadid, NULL, writer_thread, NULL);

    while(1){
            fprintf(stderr, "running ...\n");
            sleep(atoi(argv[1]));
    }
    return 0;
}
