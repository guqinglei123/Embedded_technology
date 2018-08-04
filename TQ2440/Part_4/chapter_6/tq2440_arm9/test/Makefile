CC=arm-linux-gcc
CFLAGS=-g -static
ROOTFSDIR := /home/guqinglei/Writing_code/TQ2440/rootfs/guqinglei
CURRENTDIR :=$(ROOTFSDIR)/ch06
CURRENTDIR2 :=$(realpath $(CURRENTDIR))
all: user_1 user_2 user_3 user_4 user_5
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
