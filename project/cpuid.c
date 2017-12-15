#include <stdio.h>
int main(void)
{
  unsigned int regs[4];
  __asm__(
		   "movl $0xa, %%eax\n\t"
		   "cpuid\n\t"
		   :"=a"(regs[0]), "=b"(regs[1]), "=c"(regs[2]), "=d"(regs[3])
      );

  printf("regs[0]=%u,regs[1]=%u,regs[2]=%u,regs[3]=%u\n", regs[0], regs[1], regs[2], regs[3]);
  return 0;
}
