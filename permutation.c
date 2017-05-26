#include <stdio.h>

void swap(char *a, char *b) {
  char ch;
  ch = *a;
  *a = *b;
  *b = ch;
}
void permutation(char *str, char *flag) {
  if(!*flag)
    printf("%s\n", str);
  else {
    for(char *p = flag; *p; ++p) {
      swap(p, flag);
      permutation(str, flag + 1);
      swap(p, flag);
    }
  }
}
int main(void) {
  char str[] = "abcd";
  permutation(str, str);
  return 0;
}
