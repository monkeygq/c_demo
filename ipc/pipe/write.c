#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FIFO_NAME "./fifo"
#define BUFFER_SIZE PIPE_BUF
#define TEN_MEG (1024 * 10)

int main() {
  int fd, res;
  int mode = O_WRONLY;
  int bytes = 0;
  char buffer[BUFFER_SIZE + 1];
  sprintf(buffer, "i do not know say what\n");
  if(access(FIFO_NAME, F_OK) == -1)
    mkfifo(FIFO_NAME, 0777);
  printf("Process %d opening FIFO O_WRONLY\n", getpid());
  fd = open(FIFO_NAME, mode);
  printf("Process %d opened FIFO, fd is %d\n", getpid(), fd);
  while(bytes < TEN_MEG) {
    res = write(fd, buffer, BUFFER_SIZE);
    bytes += res;
    printf("write %d bytes\n", bytes);
    sleep(1);
  }
  close(fd);
  printf("Process %d finished\n", getpid());
  return 0;
}

