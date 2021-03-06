/* test-thread.c */
#include <stdio.h>
#include <stdlib.h> /* exit */
#include <unistd.h> /* usleep */
#include <pthread.h>

#include <signal.h> // added for signal
static void signal_handler(int sig) {
  printf("signal handler for %d\n", sig);
  exit(1);
}

long int shared_resource = 0;

void *task (void *arg) {
  long int i, loop = (long)arg;          /* 引数の取得 */
  for(i=0;i<loop;i++){
    shared_resource++;
    printf("Thread [%x]: %ld %ld\n", (int)pthread_self(), i, shared_resource);
    usleep(10*1000*1000/loop);
  }
  arg = (void *)(shared_resource);
}

int main () {
  pthread_t thread1, thread2;
  long int loop1 = 10, loop2 = 20;

  signal(SIGINT, signal_handler);

  pthread_create(&thread1, NULL, task, (void *)loop1); /* thread1を生成 */
  pthread_create(&thread2, NULL, task, (void *)loop2); /* thread2を生成 */

  int ret1, ret2;
  pthread_join(thread1, (void **)&ret1);
  printf("Thread [%x]: finished, return %d.\n", (int)thread1, ret1);
  pthread_join(thread2, (void **)&ret2);
  printf("Thread [%x]: finished, return %d.\n", (int)thread2, ret2);

  printf("Done %ld\n", shared_resource);

  return 0;
}
