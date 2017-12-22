obj-m:=hello.o
PWD:=$(shell pwd)
CUR_PATH:=$(shell uname -r)
KERNELPATH:=/home/hougq/Downloads/linux-3.19

all:
	make -C $(KERNELPATH) M=$(PWD) modules
clean:
	make -C $(KERNELPATH) M=$(PWD) clean
