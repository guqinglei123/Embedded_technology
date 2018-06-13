
#define NFCONF (*(volatile unsigned long*)0x4E000000)  //???
#define NFCONT (*(volatile unsigned long*)0x4E000004)
#define NFSTAT (*(volatile unsigned char*)0x4E000020)
#define NFCMD (*(volatile unsigned char*)0x4E000008)
#define NFADDR (*(volatile unsigned char*)0x4E00000C)
#define NFDATA (*(volatile unsigned char*)0x4E000010)


#define TACLS  1     //0ns
#define TWRPH0 2     //>12ns  tcls
#define TWRPH1 1     //>5ns


void select_chip()
{
 //   NFCONT &= ~(1<<1);
     NFCONT &= ~(1<<1);

}

void deselect_chip()
{
    NFCONT |= (1<<1);
}


void clear_RnB()
{
    NFSTAT |= (1<<2);
}

void send_cmd(unsigned cmd)
{
    NFCMD = cmd;
}

void send_addr(unsigned addr)
{
    NFADDR = addr;
}


void wait_RnB()
{
    while(!(NFSTAT & (1<<2)))
    {
        ;
    }
}

void nand_reset()
{   
    //选择flash
    select_chip();

    //清除R/B
    clear_RnB();

    //发送0xff命令
    send_cmd(0xFF);
        
    //等待R/B从高电平到低电平
    wait_RnB();

    //取消选中nandflash芯片
    deselect_chip();

}



void nand_init()
{
    //初始化配置寄存器
    NFCONF = (TACLS<<12) | (TWRPH0<<8) | (TWRPH1<<4);

    //初始化控制寄存器
    NFCONT = (1<<0) | (1<<1);

    //复位
    nand_reset();


}


int nand_Erase(unsigned long addr)
{
    
    int i, ret;

    //选择nandflash芯片
    select_chip();

    //清除R/B
    clear_RnB();

    //发送0x60命令
    send_cmd(0x60);

    //发送行地址 分3次发送，每一次8bit
    send_addr(addr&0xff);
    send_addr((addr>>8)&0xff);
    send_addr((addr>>16)&0xff);


    //发送0xD0
    send_cmd(0xD0);

    //等待R/B从高电平到低电平
    wait_RnB();

    //发送0x70
    send_cmd(0x70);

    //读取写入结果
    ret = NFDATA;

    //取消选中nandflash芯片
    deselect_chip();
    return ret;

}

int nand_PageWrite(unsigned long addr,unsigned char *buff)
{
    
    int i, ret;

    //选择nandflash芯片
    select_chip();

    //清除R/B
    clear_RnB();

    //发送0x80命令
    send_cmd(0x80);

    //发列地址  分2次发送，每一次8bit
    send_addr(0x00);
    send_addr(0x00);
    //发送行地址 分3次发送，每一次8bit
    send_addr(addr&0xff);
    send_addr((addr>>8)&0xff);
    send_addr((addr>>16)&0xff);

    //写入数据
    for(i = 0; i<2048; i++)
    {
        NFDATA = buff[i];
    }
    //发送0x10
    send_cmd(0x10);

    //等待R/B从高电平到低电平
    wait_RnB();

    //发送0x70
    send_cmd(0x70);

    //读取写入结果
    ret = NFDATA;

    //取消选中nandflash芯片
    deselect_chip();
    return ret;

}

void nand_PageRead(unsigned long addr,unsigned char *buff)
{
    
    int i;

    //选择nandflash芯片
    select_chip();

    //清除R/B
    clear_RnB();

    //发送0x00命令
    send_cmd(0x00);

    //发列地址  分2次发送，每一次8bit
    send_addr(0x00);
    send_addr(0x00);
    //发送行地址 分3次发送，每一次8bit
    send_addr(addr&0xff);
    send_addr((addr>>8)&0xff);
    send_addr((addr>>16)&0xff);

    //发送0x30
    send_cmd(0x30);

    //等待R/B从高电平到低电平
    wait_RnB();

    //读取数据
    for(i = 0; i<2048; i++)
    {
        buff[i] = NFDATA;
    }

    //取消选中nandflash芯片
    deselect_chip();

}


void nand_to_ram(unsigned long start_addr,unsigned char* sdram_addr,int size)
{
    int i;
    for (i=(start_addr>>11);size>0;)
    {
        nand_PageRead(i,sdram_addr);
        size -= 2048;
        sdram_addr += 2048;
        i++;
    }
}