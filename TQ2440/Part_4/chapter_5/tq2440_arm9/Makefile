obj-m := hello.o

KDIR := /home/guqinglei/Writing_code/TQ2440/linux-tq2440
ROOTFSDIR := /home/guqinglei/Writing_code/vexpress_cortex-a9/rootfs

all:
	make -C $(KDIR) M=$(PWD) modules CROSS_COMPILE=arm-linux- ARCH=arm
	cp *.ko $(ROOTFSDIR)
	
clean:
	rm -f *.o *.ko *.order *.symvers
	

