/*
 * 两个线程同时生产gnum
 * 线程1在gnum<3时不生产
 * gnum>=10时两个线程exit
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int gnum = 0;
pthread_mutex_t mu;
pthread_cond_t cond;

static void *pthread_func1(void *arg);
static void *pthread_func2(void *arg);

int main() {
  pthread_t tid1, tid2;
  pthread_mutex_init(&mu, NULL);
  pthread_cond_init(&cond, NULL);
  pthread_create(&tid1, NULL, pthread_func1, NULL);
  pthread_create(&tid2, NULL, pthread_func2, NULL);
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  pthread_mutex_destroy(&mu);
  pthread_cond_destroy(&cond);
  printf("over!!!\n");
  return 0;
}

static void *pthread_func1(void *arg) {
  for(;;) {
    pthread_mutex_lock(&mu);
    printf("I am thread 1.\n");
    if(gnum < 3)
      pthread_cond_wait(&cond, &mu);
    if(gnum >= 10) {
      pthread_mutex_unlock(&mu);
      pthread_exit(0);
    }
    printf("thread 1 is working\n");
    sleep(1);
    gnum++;
    printf("thread 1 produce a new gnum, gnum = %d\n", gnum);
    pthread_mutex_unlock(&mu);
  }
  return NULL;
}

static void *pthread_func2(void *arg) {
  for(;;) {
    pthread_mutex_lock(&mu);
    printf("I am thread 2.\n");
    if(gnum >= 10) {
      pthread_mutex_unlock(&mu);
      pthread_exit(0);
    }
    printf("thread 2 is working\n");
    sleep(1);
    gnum++;
    printf("thread 2 produce a new gnum, gnum = %d\n", gnum);
    if(gnum == 3)
      pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mu);
  }
  return NULL;
}

