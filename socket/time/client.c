#include <iostream>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>
#include <time.h>
using namespace std;
int main() {
  int sockfd, n;
  struct sockaddr_in servaddr;
  char buf[1024];
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  servaddr.sin_port = htons(11332);
  connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
  n = recv(sockfd, buf, 1024, 0);
  buf[n] = '\0';
  printf("%s\n", buf);
  
}

