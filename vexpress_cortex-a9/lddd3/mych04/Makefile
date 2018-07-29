#
#  A simple module for helloworld
#
#  Copyright (C) 2017 aggresss (aggresss.163.com)
#
#  Licensed under GPLv2 or later.
# 
ifneq ($(KERNELRELEASE),)

MODULE_NAME := hello_module
$(MODULE_NAME)-objs := hello.o
obj-m += $(MODULE_NAME).o

else

KDIR := /home/guqinglei/Writing_code/vexpress_cortex-a9/linux_vexpress-a9
ROOTFSDIR := /home/guqinglei/Writing_code/vexpress_cortex-a9/rootfs

all:
	make -C $(KDIR) M=$(PWD) modules CROSS_COMPILE=arm-linux-gnueabi- ARCH=arm
	cp *.ko $(ROOTFSDIR)
clean:
	@rm -rf .tmp_* .*o.cmd *.o *.ko *.mod.c *.order *.symvers

endif
