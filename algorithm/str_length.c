#include <stdio.h>
size_t str_length(const char *str){ 
  const char *s;
  for(s=str; *s; ++s);
  return s-str;
}

int main(void) { 
  const char *str ="qwer";
  printf("%lu\n", str_length(str));
  return 0;
}

// size_t means unsigned long
