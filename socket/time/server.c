#include <iostream>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>
#include <time.h>

using namespace std;

int main() {
  int listenfd, connfd;
  struct sockaddr_in servaddr;
  char buf[1024];
  time_t t;
  listenfd = socket(AF_INET, SOCK_STREAM, 0);
  if(listenfd < 0) {
    cout << "socket error" << endl;
  }
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  servaddr.sin_port = htons(11332);
  bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
  listen(listenfd, 5);
  for(;;) {
    cout << "wait for conn" << endl;
    connfd = accept(listenfd, (struct sockaddr *)NULL, NULL);
    cout << "conn succ" << endl;
    t = time(NULL);
    snprintf(buf, sizeof(buf), "%.24s\r\n", ctime(&t));
    printf("current time : %s\n", buf);
    send(connfd, buf, 1024, 0);
    close(connfd);
  }
  return 0;
}

