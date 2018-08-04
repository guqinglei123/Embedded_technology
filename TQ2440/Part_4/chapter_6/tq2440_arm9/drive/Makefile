#
#需要修改obj-m 一行
#需要修改CURRENTDIR 一行
#
#

ifneq ($(KERNELRELEASE),)
	obj-m := remap_pfn_kmalloc.o
	obj-m += remap_pfn_vmalloc.o
	obj-m += remap_pfn_alloc_pages.o
else
	KDIR := /home/guqinglei/Writing_code/TQ2440/linux-tq2440
	ROOTFSDIR := /home/guqinglei/Writing_code/TQ2440/rootfs/guqinglei
	CURRENTDIR :=$(ROOTFSDIR)/ch06
	CURRENTDIR2 :=$(realpath $(CURRENTDIR))
	
default:
	make -C $(KDIR) M=$(PWD) modules CROSS_COMPILE=arm-linux-gnueabi- ARCH=arm
ifeq ($(CURRENTDIR),$(CURRENTDIR2))
	cp *.ko $(CURRENTDIR)
else
	mkdir $(CURRENTDIR)
	cp *.ko $(CURRENTDIR)
endif

clean:
	@rm -rf *.o *.mod.c *.mod.o *.ko *.order *.symvers .*.cmd .tmp_versions
endif
