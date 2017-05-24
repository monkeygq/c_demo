#include<stdio.h>
#include<assert.h>
char* str_copy(char *to, const char *from) {
  assert(to != NULL && from != NULL);
  char *p = to;
  while((*p++ = *from++) != '\0');
  return to;
}
int main(void) {
  const char *from = "qwer";
  char to[5];
  str_copy(to, from);
  printf("%s\n", to);
  return 0;
}

