#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");

void read_msr(unsigned int idx) {
	unsigned int edx, eax;
	__asm__(
				"rdmsr\n\t"
				:"=d"(edx), "=a"(eax)
				:"a"(idx)
			);
	printk(KERN_NOTICE "I am in hello.c, edx:eax = %x%x\n", edx, eax);
	printk(KERN_NOTICE "I am in hello.c, edx = %x\n", edx);
	printk(KERN_NOTICE "I am in hello.c, eax = %x\n", eax);
}

static int hello_init(void)
{
	printk(KERN_NOTICE "I am in hello.c, hello_init\n");
	read_msr(0x186);
	read_msr(0x187);
	read_msr(0x188);
	read_msr(0x189);
	return 0;
}

static void hello_exit(void)
{
	printk(KERN_NOTICE "I am in hello.c, hello_exit\n");
}

module_init(hello_init);
module_exit(hello_exit);
