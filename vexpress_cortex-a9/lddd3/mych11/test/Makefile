CC=arm-linux-gnueabi-gcc
CFLAGS=-g
ROOTFSDIR := /home/guqinglei/Writing_code/vexpress_cortex-a9/rootfs
CURRENTDIR :=$(ROOTFSDIR)/mych11
CURRENTDIR2 :=$(realpath $(CURRENTDIR))
all: user_1 user_2 user_3 user_4 user_5.c
ifeq ($(CURRENTDIR),$(CURRENTDIR2))
	cp $^ $(CURRENTDIR)
else
	mkdir $(CURRENTDIR)
	cp $^ $(CURRENTDIR)
endif


user_1:user_1.c
user_2:user_2.c
user_3:user_3.c
user_4:user_4.c
user_5:user_5.c

clean:
	$(RM) user_2 user_1 user_3 user_4 user_5
.PHONY:
	clean all
