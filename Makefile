obj-m = sx_dev.o
KERNEL_DIR = /lib/modules/$(shell uname -r)/build

all:
	make -C $(KERNEL_DIR) SUBDIRS=$(shell pwd) modules
clean:
	rm *.o *.ko *.mod.o

.PHONY:clean

