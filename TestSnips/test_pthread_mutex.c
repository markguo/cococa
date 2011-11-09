/**
 *    \file   test_pthread_mutex.c
 *    \brief  
 *    \date   2011Äê05ÔÂ16ÈÕ
 *    \author guoshiwei (guoshiwei@gmail.com)
 */

#include <pthread.h>

    pthread_mutex_t mutex;

#define LOOP_NUM 1 
void * thread_fun(void *)
{
    int i;
    for(i = 0; i < LOOP_NUM; ++i){
	pthread_mutex_lock(&mutex);
	pthread_mutex_unlock(&mutex);
    }
}
int main(int argc, char *argv[])
{
    int i;
    pthread_t tid;
    void * status;

    pthread_mutex_init(&mutex, 0);
    pthread_create(&tid, NULL, thread_fun, NULL);

    for(i = 0; i < LOOP_NUM; ++i){
	pthread_mutex_lock(&mutex);
	pthread_mutex_unlock(&mutex);
    }

    pthread_join(tid, &status);
    return 0;
}
