#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

#define PAGE_SIZE (4 * 1024)
#define BUF_SIZE (16 * PAGE_SIZE)
#define OFFSET (0)

//计算虚拟地址对应的地址，传入虚拟地址vaddr，通过paddr传出物理地址
void mem_addr(unsigned long vaddr, unsigned long *paddr)
{
    int pageSize = getpagesize(); //调用此函数获取系统设定的页面大小

    unsigned long v_pageIndex = vaddr / pageSize;            //计算此虚拟地址相对于0x0的经过的页面数
    unsigned long v_offset = v_pageIndex * sizeof(uint64_t); //计算在/proc/pid/page_map文件中的偏移量
    unsigned long page_offset = vaddr % pageSize;            //计算虚拟地址在页面中的偏移量
    uint64_t item = 0;                                       //存储对应项的值

    int fd = open("/proc/self/pagemap", O_RDONLY); //以只读方式打开/proc/pid/page_map
    if (fd == -1)                                  //判断是否打开失败
    {
        printf("open /proc/self/pagemap error\n");
        return;
    }

    if (lseek(fd, v_offset, SEEK_SET) == -1) //将游标移动到相应位置，即对应项的起始地址且判断是否移动失败
    {
        printf("sleek error\n");
        return;
    }

    if (read(fd, &item, sizeof(uint64_t)) != sizeof(uint64_t)) //读取对应项的值，并存入item中，且判断读取数据位数是否正确
    {
        printf("read item error\n");
        return;
    }

    if ((((uint64_t)1 << 63) & item) == 0) //判断present是否为0
    {
        printf("page present is 0\n");
        return;
    }

    uint64_t phy_pageIndex = (((uint64_t)1 << 55) - 1) & item; //计算物理页号，即取item的bit0-54

    *paddr = (phy_pageIndex * pageSize) + page_offset; //再加上页内偏移量就得到了物理地址
}


int main(int argc, const char *argv[])
{
    unsigned long phy = 0; //物理地址
    
    printf("pid = %d\n", getpid()); 
    printf("\n");   
    printf("the ouput of malloc(100):\n");
    printf("before malloc(100):\n");
    int fd3 = open("/dev/remap_pfn", O_RDWR);
    char *p = (char *)malloc(100); //动态内存
    //p[0] = '1';//子进程中修改动态内存
    printf("after malloc(100):\n");
    int fd4 = open("/dev/remap_pfn", O_RDWR);
    phy=0;
    mem_addr((unsigned long)p, &phy);
    printf("the ouput of user program:\n");
    printf("virtual addr: %x\n",p);
    printf("physical addr: %x\n",phy);//这里调用了brk函数，并且是修改了_edata指针。并且没有访问分配地址为什么会有物理地址，这里的物理地址对不对。


    printf("\n");
    printf("the ouput of malloc(200K):\n");
    char *p2 = (char *)malloc(200*1024); //动态内存
    //p[0] = '1';//子进程中修改动态内存
    phy=0;
    mem_addr((unsigned long)p2, &phy);
    printf("the ouput of user program:\n");
    printf("virtual addr: %x\n",p2);
    printf("physical addr: %x\n",phy);//这里调用了mmap函数。在heap和stack之间分配了一堆虚拟性区。并且没有访问分配地址为什么会有物理地址，这里的物理地址对不对。

    printf("\n");
     printf("the ouput of mmap_drive:\n");
    int fd = open("/dev/remap_pfn", O_RDWR);
    char *p3 = mmap(p2, BUF_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_LOCKED, fd, OFFSET);//为什么第一个参数不为NULL时，还是和p3一样吗？因为那个地址不符合分配要求？
    phy=0;
    mem_addr((unsigned long)p3, &phy);
    printf("the ouput of user program:\n");
    printf("virtual addr: %x\n",p3);
    printf("physical addr: %x\n",phy);
    sprintf(p3, "I am %s\n", argv[0]);//向映射区域写入数据
    printf("the write data of mmap_address %s\n", p3);
    phy=0;
    mem_addr((unsigned long)p3, &phy);
    printf("physical addr of wirte data: %x\n",phy);//这里通过mmap建立虚拟内核地址和用户地址之间的映射。为什么我写入了一些数据还是没有物理地址呢,因为映射的是内核？

    printf("\n");
    int fd2 = open("test", O_RDWR);
    char *p4 = mmap(NULL, BUF_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_LOCKED, fd2, OFFSET);//为什么第一个参数不为NULL是，不应该要和p3一样吗？
    phy=0;
    mem_addr((unsigned long)p4, &phy);
    printf("the ouput of mmap_test:\n");
    printf("virtual addr: %x\n",p4);
    printf("physical addr: %x\n",phy);//这里有物理地址。


    while (1)
        sleep(1);

    return 0;
}