obj-m:=paramirq.o
PWD:=$(shell pwd)
CUR_PATH:=$(shell uname -r)
KERNELPATH:=/home/hougq/Downloads/linux-4.14.5

all:
	make -C $(KERNELPATH) M=$(PWD) modules
clean:
	make -C $(KERNELPATH) M=$(PWD) clean
