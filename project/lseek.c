#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(void)
{
  int handle, i;
  char msg[]="This is a test";
  char ch; 
  /*create a file*/
  handle=open("TEST.log",O_CREAT|O_RDWR,S_IREAD|S_IWRITE);
  /*write some data to the file*/
  write(handle,msg,strlen(msg));
  /*seek to the begining of the file*/
  lseek(handle,0,SEEK_SET);
  /*reads chars from the file until we hit EOF*/
  while(read(handle, &ch, 1) != '\0')
    printf("%c", ch);
  printf("\n");
  close(handle);
  return 0;
}

