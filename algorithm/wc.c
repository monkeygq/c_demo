#include<stdio.h>

#define IN 1
#define OUT 0

main()
{
  int c, status, nl, nw, nc;
  status = OUT;
  nl = nw = nc = 0;
  while((c = getchar()) != EOF) {
    if(c != ' ' && c != '\n' && c != '\t') {
      if(status == OUT) {
        ++nw;
        status = IN;
      }
    }
    else
      status = OUT;

    if(c == '\n')
      ++nl;

    ++nc;
  }
  printf("%d %d %d\n", nl, nw, nc);
}
