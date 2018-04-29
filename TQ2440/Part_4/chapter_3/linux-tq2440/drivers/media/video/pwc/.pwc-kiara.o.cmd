cmd_drivers/media/video/pwc/pwc-kiara.o := arm-linux-gcc -Wp,-MD,drivers/media/video/pwc/.pwc-kiara.o.d  -nostdinc -isystem /usr/local/arm/4.3.2/bin/../lib/gcc/arm-none-linux-gnueabi/4.3.2/include -Iinclude  -I/home/guqinglei/TQ2440/Part_4/chapter_3/linux-tq2440/arch/arm/include -include include/linux/autoconf.h -D__KERNEL__ -mlittle-endian -Iarch/arm/mach-s3c2410/include -Iarch/arm/mach-s3c2400/include -Iarch/arm/mach-s3c2412/include -Iarch/arm/mach-s3c2440/include -Iarch/arm/mach-s3c2442/include -Iarch/arm/mach-s3c2443/include -Iarch/arm/plat-s3c24xx/include -Iarch/arm/plat-s3c/include -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -fno-delete-null-pointer-checks -O2 -marm -fno-omit-frame-pointer -mapcs -mno-sched-prolog -mabi=aapcs-linux -mno-thumb-interwork -D__LINUX_ARM_ARCH__=4 -march=armv4t -mtune=arm9tdmi -msoft-float -Uarm -fno-stack-protector -fno-omit-frame-pointer -fno-optimize-sibling-calls -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow   -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(pwc_kiara)"  -D"KBUILD_MODNAME=KBUILD_STR(pwc)"  -c -o drivers/media/video/pwc/pwc-kiara.o drivers/media/video/pwc/pwc-kiara.c

deps_drivers/media/video/pwc/pwc-kiara.o := \
  drivers/media/video/pwc/pwc-kiara.c \
  drivers/media/video/pwc/pwc-kiara.h \
  include/media/pwc-ioctl.h \
  include/linux/types.h \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/lbd.h) \
    $(wildcard include/config/phys/addr/t/64bit.h) \
    $(wildcard include/config/64bit.h) \
  /home/guqinglei/TQ2440/Part_4/chapter_3/linux-tq2440/arch/arm/include/asm/types.h \
  include/asm-generic/int-ll64.h \
  include/linux/posix_types.h \
  include/linux/stddef.h \
  include/linux/compiler.h \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
  include/linux/compiler-gcc.h \
    $(wildcard include/config/arch/supports/optimized/inlining.h) \
    $(wildcard include/config/optimize/inlining.h) \
  include/linux/compiler-gcc4.h \
  /home/guqinglei/TQ2440/Part_4/chapter_3/linux-tq2440/arch/arm/include/asm/posix_types.h \
  include/linux/version.h \
  drivers/media/video/pwc/pwc-uncompress.h \

drivers/media/video/pwc/pwc-kiara.o: $(deps_drivers/media/video/pwc/pwc-kiara.o)

$(deps_drivers/media/video/pwc/pwc-kiara.o):
