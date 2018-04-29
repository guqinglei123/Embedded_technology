#define ADCCON    (*(volatile unsigned *)0x58000000)   //ADC control
#define ADCTSC    (*(volatile unsigned *)0x58000004)   //ADC touch screen control
#define ADCDLY    (*(volatile unsigned *)0x58000008)   //ADC start or Interval Delay
#define ADCDAT0   (*(volatile unsigned *)0x5800000c)   //ADC conversion data 0
#define ADCDAT1   (*(volatile unsigned *)0x58000010)   //ADC conversion data 1

/*interrupt registes*/
#define SRCPND              (*(volatile unsigned long *)0x4A000000)
#define INTMSK              (*(volatile unsigned long *)0x4A000008)
#define INTOFFSET           (*(volatile unsigned long *)0x4A000014)
#define SUBSRCPND           (*(volatile unsigned long *)0x4A000018)
#define INTSUBMSK           (*(volatile unsigned long *)0x4A00001c)
#define INTPND              (*(volatile unsigned long *)0x4A000010)

int xdata,ydata;

void ts_init()
{
    //设置AD转换时钟
    ADCCON = (1<<14) |(49<<6)

    //设置中断屏蔽位，有ADC中断和触摸中断，
    //使能触摸中断，关闭ADC中断
    INTMSK = ~(1<<31);
    INTSUBMSK = ~(1<<9);
    //进入中断等待模式
    ADCTSC = 0xd3;


}

void ts_handler()
{
    //启动xy坐标转换
    ADCTSC = (1<<2);
    ADCCON |= （1<<0）；
    //等待坐标转换完成
    while(!(ADCCON&(1<<15)))
    //获得坐标
    xdata = ADCDATA0 & 0x3fff;
    ydata = ADCDATA1 & 0x3fff; 
    //清除按下中断
    SUBSRCPND |= (1<<9);
    SRCPND = (1<<31);
    INTPND = (1<<31);

    //进入等待按下弹起中断
    ADCTSC = 0Xd3;
    ADCTSC |=(1<<8);
    while(1)
    {
        if(SUBSRCPND |= (1<<9))
            break;
    }

    //清除弹起中断
     SUBSRCPND |= (1<<9);
    SRCPND = (1<<31);
    INTPND = (1<<31);   
    printf("x is %d,y is %d",xdata,ydata)
    //再次进入等待按下中断状态
    ADCTSC= 0Xd3;

}
