#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <pthread.h>

typedef int bool;
#define true 1
#define false 0


void * run_thread(void *);
void write_log(bool use_stdio);
int main(int argc, char **argv)
{
  pthread_t threads[1024];
  int thread_num = 0;
  int i = 0;

  if(argc < 2){
    printf("usage: %s thread_num\n",argv[0]);
  }
  thread_num = atoi(argv[1]);

  for(i = 0; i < thread_num; ++i){
    pthread_create(&threads[i], NULL, run_thread, NULL);
  }


  for(i = 0; i < thread_num; ++i){
    pthread_join(threads[i], NULL);
  }

  return 0;
}

void * run_thread(void * arg)
{
  while(1){
    write_log(true);
  }

  return NULL;
}

void write_log(bool use_stdio)
{
  char buf[1024];
  char ctime_now[1024];
  time_t now = time(NULL);

  ctime_r(&now, ctime_now);
  int n = snprintf(buf, sizeof(buf), "%s %d\n", ctime_now, pthread_self());
  buf[n] = '\0';
  if(use_stdio){
    fwrite(buf, 1, n, stderr);
  }
  else{
    write(2, buf, n);
  }
}
