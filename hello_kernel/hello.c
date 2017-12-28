#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");

void read_msr(unsigned int idx) {
	unsigned int edx, eax;
	__asm__(
				"rdmsr\n\t"
				:"=d"(edx), "=a"(eax)
				:"c"(idx)
			);
	printk(KERN_NOTICE "I am in hello.c read_msr, idx = %x, edx:eax = %04x%04x\n", idx, edx, eax);
	printk(KERN_NOTICE "I am in hello.c read_msr, edx = %04x\n", edx);
	printk(KERN_NOTICE "I am in hello.c read_msr, eax = %04x\n", eax);
}

void write_msr(unsigned int idx, unsigned int low, unsigned int high) {
	__asm__(
				"wrmsr\n\t"
				::"c"(idx), "d"(high), "a"(low)
			);
	printk(KERN_NOTICE "I am in hello.c write_msr, idx = %x, edx:eax = %04x%04x\n", idx, high, low);
	printk(KERN_NOTICE "I am in hello.c write_msr, edx = %04x\n", high);
	printk(KERN_NOTICE "I am in hello.c write_msr, eax = %04x\n", low);
}

static int hello_init(void)
{
	printk(KERN_NOTICE "I am in hello.c, hello_init\n");
	read_msr(0x38e);
	read_msr(0x38f);
	read_msr(0x390);
	write_msr(0x1d9, 1u << 11 | 1u << 12, 0);
	read_msr(0x1d9);
	return 0;
}

static void hello_exit(void)
{
	printk(KERN_NOTICE "I am in hello.c, hello_exit\n");
}

module_init(hello_init);
module_exit(hello_exit);
