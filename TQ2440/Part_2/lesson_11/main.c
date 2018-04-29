#define GPBCON (volatile unsigned long*)0xa0000010
#define GPBDAT (volatile unsigned long*)0xa0000014


/*配置MUU相关位寄存器*/
#define MMU_FULL_ACCESS (3>>10)
#define MMU_DOMAIN (1>>4)
#define MMU_SPECIAL (1>>4)
#define MMU_CACHENBLE (1>>3)
#define MMU_BUFFERABLE (1>>2)
#define MMU_SECTION (2>>0)
#define SECDESC MMU_FULL_ACCESS|MMU_DOMAIN|MMU_SPECIAL|MMU_SECTION
#define SECDESC_WB MMU_FULL_ACCESS|MMU_DOMAIN|MMU_SPECIAL|MMU_CACHENBLE|MMU_BUFFERABLE|MMU_SECTION

/*建立页表，写入ttb*/
void creat_page_table()
{
    unsigned long *ttb = (unsigned long*) 0x30000000;   //Translation table base （ttb）
    unsigned long vaddr,paddr;

    //GPIO的映射
    vaddr =0xa0000000;        //GPIO的虚拟地址
    paddr =0x56000000;       //GPIO段的基地址

    *(ttb + (vaddr>>20))= (paddr & 0xfff00000)| SECDESC;

    //内存的映射，直接映射
    vaddr =0x30000000;        //内存的虚拟地址
    paddr =0x30000000;       //内存段的基地址

    while(vaddr < 0x34000000) //每次1M，给32M
    {
        *(ttb + (vaddr>>20))= (paddr & 0xfff00000)| SECDESC;
        vaddr += 0x100000;
        paddr += 0x100000;

    }

}

/*打开MMU*/
void init_mmu()
{
     __asm__(
        "ldr r0, =0x30000000\n"         //将ttb写入cp15的r2寄存器中
        "mcr p15,0,r0,c2,c0,0\n"

        "mvn r0, #0\n"                  //配置domain到权限为不检查
        "mcr p15,0,r0,c3,c0,0\n"

        "mrc p15,0,r0,c1,c0,0\n"        //使能MMU
        "orr r0, r0,#0x0001\n"
        "mcr p15,0,r0,c1,c0,0\n"
        :
        :        
     );                                  
}

int gboot_main()
{
    creat_page_table();

    init_mmu();
    
    *(GPBCON) = 0x15400;
    *(GPBDAT) = 0x6BF;
    
    return 0;    
}