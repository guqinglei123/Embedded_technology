cmd_runit/chpst.o := arm-linux-gcc -Wp,-MD,runit/.chpst.o.d   -std=gnu99 -Iinclude -Ilibbb  -include include/autoconf.h -D_GNU_SOURCE -DNDEBUG -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -D"BB_VER=KBUILD_STR(1.13.3)" -DBB_BT=AUTOCONF_TIMESTAMP  -Wall -Wshadow -Wwrite-strings -Wundef -Wstrict-prototypes -Wunused -Wunused-parameter -Wmissing-prototypes -Wmissing-declarations -Wdeclaration-after-statement -Wold-style-definition -fno-builtin-strlen -finline-limit=0 -fomit-frame-pointer -ffunction-sections -fdata-sections -fno-guess-branch-probability -funsigned-char -static-libgcc -falign-functions=1 -falign-jumps=1 -falign-labels=1 -falign-loops=1 -Os    -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(chpst)"  -D"KBUILD_MODNAME=KBUILD_STR(chpst)" -c -o runit/chpst.o runit/chpst.c

deps_runit/chpst.o := \
  runit/chpst.c \
    $(wildcard include/config/softlimit.h) \
    $(wildcard include/config/chpst.h) \
    $(wildcard include/config/setuidgid.h) \
    $(wildcard include/config/envuidgid.h) \
    $(wildcard include/config/envdir.h) \
    $(wildcard include/config/st.h) \
  include/libbb.h \
    $(wildcard include/config/selinux.h) \
    $(wildcard include/config/locale/support.h) \
    $(wildcard include/config/feature/shadowpasswds.h) \
    $(wildcard include/config/use/bb/pwd/grp.h) \
    $(wildcard include/config/use/bb/shadow.h) \
    $(wildcard include/config/lfs.h) \
    $(wildcard include/config/feature/buffers/go/on/stack.h) \
    $(wildcard include/config/buffer.h) \
    $(wildcard include/config/ubuffer.h) \
    $(wildcard include/config/feature/buffers/go/in/bss.h) \
    $(wildcard include/config/inux.h) \
    $(wildcard include/config/feature/ipv6.h) \
    $(wildcard include/config/feature/check/names.h) \
    $(wildcard include/config/feature/prefer/applets.h) \
    $(wildcard include/config/busybox/exec/path.h) \
    $(wildcard include/config/getopt/long.h) \
    $(wildcard include/config/feature/pidfile.h) \
    $(wildcard include/config/feature/syslog.h) \
    $(wildcard include/config/feature/individual.h) \
    $(wildcard include/config/o.h) \
    $(wildcard include/config/ntf.h) \
    $(wildcard include/config/t.h) \
    $(wildcard include/config/l.h) \
    $(wildcard include/config/wn.h) \
    $(wildcard include/config/.h) \
    $(wildcard include/config/route.h) \
    $(wildcard include/config/feature/hwib.h) \
    $(wildcard include/config/feature/crond/d.h) \
    $(wildcard include/config/use/bb/crypt.h) \
    $(wildcard include/config/ioctl/hex2str/error.h) \
    $(wildcard include/config/feature/editing.h) \
    $(wildcard include/config/feature/editing/history.h) \
    $(wildcard include/config/ture/editing/savehistory.h) \
    $(wildcard include/config/feature/editing/savehistory.h) \
    $(wildcard include/config/feature/tab/completion.h) \
    $(wildcard include/config/feature/username/completion.h) \
    $(wildcard include/config/feature/editing/vi.h) \
    $(wildcard include/config/feature/topmem.h) \
    $(wildcard include/config/feature/top/smp/process.h) \
    $(wildcard include/config/killall.h) \
    $(wildcard include/config/pgrep.h) \
    $(wildcard include/config/pkill.h) \
    $(wildcard include/config/pidof.h) \
    $(wildcard include/config/sestatus.h) \
    $(wildcard include/config/feature/devfs.h) \
  include/platform.h \
    $(wildcard include/config/werror.h) \
    $(wildcard include/config///.h) \
    $(wildcard include/config/nommu.h) \
    $(wildcard include/config//nommu.h) \
    $(wildcard include/config//mmu.h) \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/byteswap.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/byteswap.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/endian.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/features.h \
    $(wildcard include/config/c99.h) \
    $(wildcard include/config/c95.h) \
    $(wildcard include/config/ix.h) \
    $(wildcard include/config/ix2.h) \
    $(wildcard include/config/ix199309.h) \
    $(wildcard include/config/ix199506.h) \
    $(wildcard include/config/en.h) \
    $(wildcard include/config/en/extended.h) \
    $(wildcard include/config/x98.h) \
    $(wildcard include/config/en2k.h) \
    $(wildcard include/config/gefile.h) \
    $(wildcard include/config/gefile64.h) \
    $(wildcard include/config/e/offset64.h) \
    $(wildcard include/config/d.h) \
    $(wildcard include/config/c.h) \
    $(wildcard include/config/ile.h) \
    $(wildcard include/config/ntrant.h) \
    $(wildcard include/config/tify/level.h) \
    $(wildcard include/config/i.h) \
    $(wildcard include/config/ern/inlines.h) \
    $(wildcard include/config/ern/inlines/in/libc.h) \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/predefs.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/sys/cdefs.h \
    $(wildcard include/config/espaces.h) \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/wordsize.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/gnu/stubs.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/endian.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/arpa/inet.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/netinet/in.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/stdint.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/wchar.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/sys/socket.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/sys/uio.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/sys/types.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/types.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/typesizes.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/time.h \
  /usr/local/arm/4.3.2/bin/../lib/gcc/arm-none-linux-gnueabi/4.3.2/include/stddef.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/sys/select.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/select.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/sigset.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/time.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/sys/sysmacros.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/pthreadtypes.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/uio.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/socket.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/sockaddr.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/asm/socket.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/asm/sockios.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/in.h \
  /usr/local/arm/4.3.2/bin/../lib/gcc/arm-none-linux-gnueabi/4.3.2/include/stdbool.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/sys/mount.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/sys/ioctl.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/ioctls.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/asm/ioctls.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/asm/ioctl.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/asm-generic/ioctl.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/ioctl-types.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/sys/ttydefaults.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/ctype.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/xlocale.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/dirent.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/dirent.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/posix1_lim.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/local_lim.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/linux/limits.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/errno.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/errno.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/linux/errno.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/asm/errno.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/asm-generic/errno.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/asm-generic/errno-base.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/fcntl.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/fcntl.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/sys/stat.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/stat.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/inttypes.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/netdb.h \
    $(wildcard include/config/3/ascii/rules.h) \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/rpc/netdb.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/siginfo.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/netdb.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/setjmp.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/setjmp.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/signal.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/signum.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/sigaction.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/sigcontext.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/asm/sigcontext.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/sigstack.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/sys/ucontext.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/sys/procfs.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/sys/time.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/sys/user.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/sigthread.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/stdio.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/libio.h \
    $(wildcard include/config/a.h) \
    $(wildcard include/config/ar/t.h) \
    $(wildcard include/config//io/file.h) \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/_G_config.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/wchar.h \
  /usr/local/arm/4.3.2/bin/../lib/gcc/arm-none-linux-gnueabi/4.3.2/include/stdarg.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/stdio_lim.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/sys_errlist.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/stdlib.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/waitflags.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/waitstatus.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/alloca.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/string.h \
    $(wildcard include/config/ing/inlines.h) \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/sys/poll.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/poll.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/sys/mman.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/mman.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/sys/wait.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/sys/resource.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/resource.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/termios.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/termios.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/unistd.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/posix_opt.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/environments.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/confname.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/getopt.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/utime.h \
  /usr/local/arm/4.3.2/bin/../lib/gcc/arm-none-linux-gnueabi/4.3.2/include-fixed/limits.h \
  /usr/local/arm/4.3.2/bin/../lib/gcc/arm-none-linux-gnueabi/4.3.2/include-fixed/syslimits.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/limits.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/posix2_lim.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/xopen_lim.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/sys/param.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/linux/param.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/asm/param.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/mntent.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/paths.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/sys/statfs.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/statfs.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/locale.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/locale.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/pwd.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/grp.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/shadow.h \
  include/pwd_.h \
  include/grp_.h \
  include/shadow_.h \
  include/xatonum.h \

runit/chpst.o: $(deps_runit/chpst.o)

$(deps_runit/chpst.o):
