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
  char buffer[BUFSIZ + 1];
  int shmid;
  shmid = shmget((key_t)1234, sizeof(struct shared_use_st), 0666 | IPC_CREAT);
  shm = shmat(shmid, (void *)0, 0);
  printf("shared mem attached at %p\n", shm);
  shared = (struct shared_use_st *)shm;
  while(running) {
    while(shared->written != 0) {
      printf("Waiting for reading\n");
      sleep(1);
    }
    printf("Writing content: ");
    fgets(buffer, BUFSIZ, stdin);
    strncpy(shared->text, buffer, TEXT_SZ);
    shared->written += 1;
    if(strncmp(buffer, "end", 3) == 0)
      running = 0;
  }
  shmdt(shm);
  return 0;
}
