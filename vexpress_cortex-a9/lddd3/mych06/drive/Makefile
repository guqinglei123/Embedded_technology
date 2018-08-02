ifneq ($(KERNELRELEASE),)
	obj-m := remap_pfn_kmalloc.o
	obj-m += remap_pfn_vmalloc.o
	obj-m += remap_pfn_alloc_pages.o
else
	KDIR := /home/guqinglei/Writing_code/vexpress_cortex-a9/linux_vexpress-a9
	ROOTFSDIR := /home/guqinglei/Writing_code/vexpress_cortex-a9/rootfs
	CURRENTDIR :=$(ROOTFSDIR)/mych11
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
