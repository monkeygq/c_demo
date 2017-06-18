#include <stdio.h>
int main(void)
{
  int regs[4];
  __asm__("movl $0x0b, %eax");
  __asm__(
           "cpuid"
           :"=a"(regs[0]), "=b"(regs[1]), "=c"(regs[2]), "=d"(regs[3])
      );

  printf("regs[0]=%d,regs[1]=%d,regs[2]=%d,regs[3]=%d\n", regs[0], regs[1], regs[2], regs[3]);
  return 0;
}
