/*
 * =====================================================================================
 *
 *       Filename:  test_exception_in_thread.cpp
 *
 *    Description:  Can we catch a exception in another thread?
 *
 *        Version:  1.0
 *        Created:  01/11/2010 01:44:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Guo Shiwei (), guoshiwei@sohu-rd.com
 *        Company:  sohu
 *
 * =====================================================================================
 */


#include <pthread.h>
#include <stdexcept>

void * in_thread(void *param)
{
    throw std::runtime_error("exctption in thread");
}

int main(int argc, char **argv)
{
    try{
        pthread_t tid;
        pthread_create(&tid, NULL, in_thread, NULL);
        printf("sleep in main thread");
        sleep(10);
    }
    catch(std::runtime_error &e){
        printf("catch exception: %s\n", e.what());
    }
    catch ( ... ){
        printf("catch unknow exception");
    }
}
