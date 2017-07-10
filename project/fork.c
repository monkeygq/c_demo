#include <stdio.h>
#include <unistd.h>

int main(void) {
  pid_t pid;
  printf("i am start, PID is %d\n", getpid());
  pid = fork();
  if(pid < 0) {
    printf("error\n");
  }
  else if(pid == 0) 
    printf("i am child, fork() returns : %d, PID is : %d\n", pid, getpid());
  else
    printf("i am parent, fork() retrurns : %d, PID is : %d\n", pid, getpid());
  return 0;
}
/*
 * output : 
 *
 * i am start, PID is 6286
 * i am parent, return var of fork() is : 6287, PID is : 6286
 * i am child, return var of fork() is : 0, PID is : 6287
 */

/*
 * in parent process fork() returns child process's PID
 * in child process fork() returns 0
 */
