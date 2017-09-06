#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/shm.h>
#define TEXT_SZ 2048

struct shared_use_st
{
  int written;//作为一个标志，非0：表示可读，0表示可写
  char text[TEXT_SZ];//记录写入和读取的文本
};

int main() {
  int running = 1;
  void *shm = NULL;
  struct shared_use_st *shared = NULL;
  int shmid;
  shmid = shmget((key_t)1234, sizeof(struct shared_use_st), 0666 | IPC_CREAT);
  shm = shmat(shmid, (void *)0, 0);
  printf("shared mem attached at %p\n", shm);
  shared = (struct shared_use_st *)shm;
  while(running) {
    if(shared->written != 0) {
      printf("Read from shared mem: %s", shared->text);
      shared->written = 0;
      if(strncmp(shared->text, "end", 3) == 0)
        running = 0;
    }
    else
      sleep(1);
  }
  shmdt(shm);
  shmctl(shmid, IPC_RMID, 0);
  return 0;
}

