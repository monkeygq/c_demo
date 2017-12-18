/*
usage: Compiling this file by make 
and using the following command to insert the mode which the make generated just now

command: sudo insmod filename.ko irq=1 devname=myirq

This interrupt shared the one irq with keyboard
*/

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/interrupt.h>

static int irq;
static char* devname;
static struct tasklet_struct mytasklet;

module_param(irq,int,0644);
module_param(devname,charp,0644);

struct myirq
{
	int devid;
};
struct myirq mydev={1119};

static void mytasklet_handler(unsigned long data)
{
	printk(KERN_NOTICE "tasklet is wroking..\n");
}

static irqreturn_t myirq_handler(int irq,void* dev)
{
	struct myirq mydev;
	static int count=0;
	mydev=*(struct myirq*)dev;
	printk(KERN_NOTICE "key:%d..\n",count+1);
	printk(KERN_NOTICE "devid:%d ISR is working..\n",mydev.devid);
	printk(KERN_NOTICE "Bottom half will be working..\n");
	tasklet_init(&mytasklet,mytasklet_handler,0);
	tasklet_schedule(&mytasklet);
	printk(KERN_NOTICE "ISR is leaving..\n");
	count++;
	return IRQ_HANDLED;
}

static int __init myirq_init(void)
{
	printk(KERN_NOTICE "Module is working..\n");
	if(request_irq(irq,myirq_handler,IRQF_SHARED,devname,&mydev)!=0)
	{
		printk(KERN_NOTICE "%s request IRQ:%d failed..\n",devname,irq);
		return -1;
	}
	printk(KERN_NOTICE "%s rquest IRQ:%d success..\n",devname,irq);
	return 0;
}

static void __exit myirq_exit(void)
{
	printk(KERN_NOTICE "Module is leaving..\n");
	free_irq(irq,&mydev);
	printk(KERN_NOTICE "%s request IRQ:%d success..\n",devname,irq);
}



module_init(myirq_init);
module_exit(myirq_exit);
MODULE_LICENSE("GPL");


