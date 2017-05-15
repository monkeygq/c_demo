#include <stdio.h>

int test(int para){
  return para%2;
}
int main(void) { 
  struct ops {
    int (*reminder_by_2)(int para);
  };
  struct ops my_ops = {
    .reminder_by_2 = test,
  };
  printf("%d\n", my_ops.reminder_by_2(6));
  return 0;
}
