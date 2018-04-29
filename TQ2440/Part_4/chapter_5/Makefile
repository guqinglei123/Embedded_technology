obj-m := helloworld.o

KDIR := /home/guqinglei/TQ2440/Part_4/chapter_3/linux-tq2440

all:
	make -C $(KDIR) M=$(PWD) modules CROSS_COMPILE=arm-linux- ARCH=arm
	
clean:
	rm -f *.o *.ko *.order *.symvers
	

