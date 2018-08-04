#
#需要修改CURRENTDIR 一行
#
#

CC=arm-linux-gnueabi-gcc
CFLAGS=-g
ROOTFSDIR := /home/guqinglei/Writing_code/vexpress_cortex-a9/rootfs
CURRENTDIR :=$(ROOTFSDIR)/ch06
CURRENTDIR2 :=$(realpath $(CURRENTDIR))
all: read-mem write-mem
ifeq ($(CURRENTDIR),$(CURRENTDIR2))
	cp $^ $(CURRENTDIR)
else
	mkdir $(CURRENTDIR)
	cp $^ $(CURRENTDIR)
endif


read-mem:read-mem.c
write-mem:write-mem.c

clean:
	$(RM) read-mem write-mem
.PHONY:
	clean all
