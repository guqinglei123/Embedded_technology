cmd_arch/arm/kernel/entry-armv.o := arm-linux-gcc -Wp,-MD,arch/arm/kernel/.entry-armv.o.d  -nostdinc -isystem /usr/local/arm/4.3.2/bin/../lib/gcc/arm-none-linux-gnueabi/4.3.2/include -Iinclude  -I/home/guqinglei/TQ2440/Part_4/chapter_3/linux-tq2440/arch/arm/include -include include/linux/autoconf.h -D__KERNEL__ -mlittle-endian -Iarch/arm/mach-s3c2410/include -Iarch/arm/mach-s3c2400/include -Iarch/arm/mach-s3c2412/include -Iarch/arm/mach-s3c2440/include -Iarch/arm/mach-s3c2442/include -Iarch/arm/mach-s3c2443/include -Iarch/arm/plat-s3c24xx/include -Iarch/arm/plat-s3c/include -D__ASSEMBLY__ -mabi=aapcs-linux -mno-thumb-interwork -D__LINUX_ARM_ARCH__=4 -march=armv4t -mtune=arm9tdmi -msoft-float       -c -o arch/arm/kernel/entry-armv.o arch/arm/kernel/entry-armv.S

deps_arch/arm/kernel/entry-armv.o := \
  arch/arm/kernel/entry-armv.S \
    $(wildcard include/config/smp.h) \
    $(wildcard include/config/local/timers.h) \
    $(wildcard include/config/kprobes.h) \
    $(wildcard include/config/aeabi.h) \
    $(wildcard include/config/trace/irqflags.h) \
    $(wildcard include/config/preempt.h) \
    $(wildcard include/config/needs/syscall/for/cmpxchg.h) \
    $(wildcard include/config/mmu.h) \
    $(wildcard include/config/neon.h) \
    $(wildcard include/config/cpu/arm610.h) \
    $(wildcard include/config/cpu/arm710.h) \
    $(wildcard include/config/iwmmxt.h) \
    $(wildcard include/config/crunch.h) \
    $(wildcard include/config/vfp.h) \
    $(wildcard include/config/cpu/32v6k.h) \
    $(wildcard include/config/has/tls/reg.h) \
    $(wildcard include/config/tls/reg/emul.h) \
    $(wildcard include/config/arm/thumb.h) \
  /home/guqinglei/TQ2440/Part_4/chapter_3/linux-tq2440/arch/arm/include/asm/memory.h \
    $(wildcard include/config/page/offset.h) \
    $(wildcard include/config/highmem.h) \
    $(wildcard include/config/dram/size.h) \
    $(wildcard include/config/dram/base.h) \
    $(wildcard include/config/zone/dma.h) \
    $(wildcard include/config/discontigmem.h) \
    $(wildcard include/config/sparsemem.h) \
  include/linux/compiler.h \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
  include/linux/const.h \
  arch/arm/mach-s3c2410/include/mach/memory.h \
  /home/guqinglei/TQ2440/Part_4/chapter_3/linux-tq2440/arch/arm/include/asm/sizes.h \
  include/asm-generic/memory_model.h \
    $(wildcard include/config/flatmem.h) \
    $(wildcard include/config/sparsemem/vmemmap.h) \
  /home/guqinglei/TQ2440/Part_4/chapter_3/linux-tq2440/arch/arm/include/asm/glue.h \
    $(wildcard include/config/cpu/abrt/lv4t.h) \
    $(wildcard include/config/cpu/abrt/ev4.h) \
    $(wildcard include/config/cpu/abrt/ev4t.h) \
    $(wildcard include/config/cpu/abrt/ev5tj.h) \
    $(wildcard include/config/cpu/abrt/ev5t.h) \
    $(wildcard include/config/cpu/abrt/ev6.h) \
    $(wildcard include/config/cpu/abrt/ev7.h) \
    $(wildcard include/config/cpu/pabrt/ifar.h) \
    $(wildcard include/config/cpu/pabrt/noifar.h) \
  /home/guqinglei/TQ2440/Part_4/chapter_3/linux-tq2440/arch/arm/include/asm/vfpmacros.h \
    $(wildcard include/config/vfpv3.h) \
  /home/guqinglei/TQ2440/Part_4/chapter_3/linux-tq2440/arch/arm/include/asm/vfp.h \
  arch/arm/mach-s3c2410/include/mach/entry-macro.S \
  arch/arm/mach-s3c2410/include/mach/hardware.h \
    $(wildcard include/config/cpu/s3c2400.h) \
    $(wildcard include/config/cpu/s3c2440.h) \
    $(wildcard include/config/cpu/s3c2412.h) \
    $(wildcard include/config/no/multiword/io.h) \
  arch/arm/mach-s3c2410/include/mach/map.h \
  arch/arm/plat-s3c/include/plat/map-base.h \
  arch/arm/plat-s3c24xx/include/plat/map.h \
    $(wildcard include/config/cpu/s3c2413.h) \
    $(wildcard include/config/cpu/s3c2412/only.h) \
  /home/guqinglei/TQ2440/Part_4/chapter_3/linux-tq2440/arch/arm/include/asm/irq.h \
  arch/arm/mach-s3c2410/include/mach/irqs.h \
    $(wildcard include/config/cpu/s3c2443.h) \
  /home/guqinglei/TQ2440/Part_4/chapter_3/linux-tq2440/arch/arm/include/asm/thread_notify.h \
  /home/guqinglei/TQ2440/Part_4/chapter_3/linux-tq2440/arch/arm/include/asm/unwind.h \
    $(wildcard include/config/arm/unwind.h) \
  arch/arm/kernel/entry-header.S \
    $(wildcard include/config/frame/pointer.h) \
    $(wildcard include/config/alignment/trap.h) \
  include/linux/init.h \
    $(wildcard include/config/modules.h) \
    $(wildcard include/config/hotplug.h) \
  include/linux/section-names.h \
  include/linux/stringify.h \
  include/linux/linkage.h \
  /home/guqinglei/TQ2440/Part_4/chapter_3/linux-tq2440/arch/arm/include/asm/linkage.h \
  /home/guqinglei/TQ2440/Part_4/chapter_3/linux-tq2440/arch/arm/include/asm/assembler.h \
    $(wildcard include/config/cpu/feroceon.h) \
  /home/guqinglei/TQ2440/Part_4/chapter_3/linux-tq2440/arch/arm/include/asm/ptrace.h \
  /home/guqinglei/TQ2440/Part_4/chapter_3/linux-tq2440/arch/arm/include/asm/hwcap.h \
  include/asm/asm-offsets.h \
  /home/guqinglei/TQ2440/Part_4/chapter_3/linux-tq2440/arch/arm/include/asm/errno.h \
  include/asm-generic/errno.h \
  include/asm-generic/errno-base.h \
  /home/guqinglei/TQ2440/Part_4/chapter_3/linux-tq2440/arch/arm/include/asm/thread_info.h \
    $(wildcard include/config/arm/thumbee.h) \
  /home/guqinglei/TQ2440/Part_4/chapter_3/linux-tq2440/arch/arm/include/asm/fpstate.h \

arch/arm/kernel/entry-armv.o: $(deps_arch/arm/kernel/entry-armv.o)

$(deps_arch/arm/kernel/entry-armv.o):
