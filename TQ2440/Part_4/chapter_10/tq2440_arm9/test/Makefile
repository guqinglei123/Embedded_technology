CC=arm-linux-gcc
CFLAGS=-g -static
ROOTFSDIR := /home/guqinglei/Writing_code/TQ2440/rootfs/guqinglei
CURRENTDIR :=$(ROOTFSDIR)/ch10
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
