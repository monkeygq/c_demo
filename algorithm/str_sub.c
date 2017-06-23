#include <stdio.h>

char* str_sub(const char *str, const char *sub) {
  if(!*sub) return (char *)str;
  const char *sub_end, *p_str, *p_sub;
  const char *str_flag = str;
  const char *p;
  for(sub_end = &sub[1]; *sub_end; ++sub_end) {
    str_flag++;
  }
  for(p = str; *str_flag; ++str_flag, ++p) {
    p_str = p;
    p_sub = sub;
    while(*p_str && *p_sub && *p_str == *p_sub) {
      p_str++;
      p_sub++;
    }
    if(p_sub == sub_end) return (char *)p;
  }
  return NULL;
}
int main(void) {
  char *ret;
  ret = str_sub("qqwweer", "qq");
  if(ret) {
    printf("%s\n", ret);
  }
  else {
    printf("%s\n", "not found");
  }
  return 0;
}
