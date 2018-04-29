cmd_.tmp_kallsyms1.o := arm-linux-gcc -Wp,-MD,./..tmp_kallsyms1.o.d -D__ASSEMBLY__ -mabi=aapcs-linux -mno-thumb-interwork -D__LINUX_ARM_ARCH__=4 -march=armv4t -mtune=arm9tdmi -msoft-float   -nostdinc -isystem /usr/local/arm/4.3.2/bin/../lib/gcc/arm-none-linux-gnueabi/4.3.2/include -Iinclude  -I/home/guqinglei/TQ2440/Part_4/chapter_3/linux-tq2440/arch/arm/include -include include/linux/autoconf.h -D__KERNEL__ -mlittle-endian -Iarch/arm/mach-s3c2410/include -Iarch/arm/mach-s3c2400/include -Iarch/arm/mach-s3c2412/include -Iarch/arm/mach-s3c2440/include -Iarch/arm/mach-s3c2442/include -Iarch/arm/mach-s3c2443/include -Iarch/arm/plat-s3c24xx/include -Iarch/arm/plat-s3c/include    -c -o .tmp_kallsyms1.o .tmp_kallsyms1.S

deps_.tmp_kallsyms1.o := \
  .tmp_kallsyms1.S \
  /home/guqinglei/TQ2440/Part_4/chapter_3/linux-tq2440/arch/arm/include/asm/types.h \
  include/asm-generic/int-ll64.h \

.tmp_kallsyms1.o: $(deps_.tmp_kallsyms1.o)

$(deps_.tmp_kallsyms1.o):
