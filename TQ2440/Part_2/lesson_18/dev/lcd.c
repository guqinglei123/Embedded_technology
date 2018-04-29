#define GPCCON (*(volatile unsigned long*)0x56000020)
#define GPDCON (*(volatile unsigned long*)0x56000030)
#define GPGCON (*(volatile unsigned long *)0x56000060)
#define LCDCON1 (*(volatile unsigned long *)0x4D000000)
#define LCDCON2 (*(volatile unsigned long *)0x4D000004)
#define LCDCON3 (*(volatile unsigned long *)0x4D000008)
#define LCDCON4 (*(volatile unsigned long *)0x4D00000C)
#define LCDCON5 (*(volatile unsigned long *)0x4D000010)
#define LCDSADDR1 (*(volatile unsigned long *)0x4D000014)
#define LCDSADDR2 (*(volatile unsigned long *)0x4D000018)
#define LCDSADDR3 (*(volatile unsigned long *)0x4D00001C)
#define TPAL      (*(volatile unsigned long *)0x4D000050)

#define HCLK 100
#define VCLK 10
#define ROW    480
#define COLUMN 272

#define CLKVAL  (HCLK/(VCLK*2))-1  //VCLK = HCLK(100)/((CLKVAL+1)*2)
#define VBPD    1 //2-1
#define LINEVAL COLUMN-1//显示屏一行的GRB点数480-1
#define VFPD    1 //2-1
#define VSPW    9  //10-1
#define HBPD    1 //2-1
#define HOZVAL  ROW-1//显示屏的行数272-1
#define HFPD    1 //2-1
#define HSPW    40//41-1

unsigned short LCDBUFF[COLUMN][ROW];//short 代表两个字节


//引脚初始化
void lcd_port_init()
{
    GPCCON = 0xaaaaaaaa;
    GPDCON = 0xaaaaaaaa;

}


//控制寄存器的初始化
void lcd_control_init()
{
    //选择LCD屏的类型
    LCDCON1 = (0X3<<5) | (0XC<<1) |(0X0<<0);
    //时钟初始化
    LCDCON1 |= (CLKVAL<<8);
    LCDCON2 = (VBPD<<24)|(LINEVAL<<14)|(VFPD<<6)|(VSPW);
    LCDCON3 = (HBPD<<19)|(HOZVAL<<8)|(HFPD);
    LCDCON4 = HSPW; 
    //帧缓冲的初始化，分配内存
    //告知DMA内存的地址 起始地址  结束地址 两个像数点的间隔  行的宽度（半字）
    LCDSADDR1 = (((unsigned int)LCDBUFF >> 22)<<21) | ((((unsigned int)LCDBUFF >> 1)&0X1FFFFF));
    LCDSADDR2 = (((unsigned int)LCDBUFF+ROW*COLUMN*2 )>> 1)&0X1FFFFF;
//    LCDSADDR3 = （0<<11）|(ROW*2/2);
    LCDSADDR3 = (0<<11) | (ROW*2/2);
    //其他初始化
    LCDCON5 = (1<<11)|(1<<9)|(1<<8)|(1<<0);
    TPAL = 0;
}

void lcd_init()
{
    lcd_port_init();
    lcd_control_init();

    //打开LCD电源
    GPGCON |= (0x3<<8);
    LCDCON5 |= (1<<3);

    //打开LCD控制器
    LCDCON1 |= 1;
}

void point(unsigned int x,unsigned int y,unsigned int color)
{
    unsigned int red,green, blue;
    red = (color>>19) & 0x1f;
    green = (color>>10) & 0x3f;
    blue = (color>>3) & 0x1f;
    LCDBUFF[y][x] = (unsigned short)((red<<11)|(green<<5)|blue);
}
void DrawLine()
{

}

void Paint_Bmp(unsigned short x0,unsigned short y0,unsigned short wide,unsigned short high,const unsigned short *bmp)
{
    unsigned short x,y;
    unsigned short c;
    unsigned int p = 0;
    
    for( y = y0 ; y < y0+high ; y++ )
    {
    	for( x = x0 ; x < x0+wide ; x++ )
    	{
    	    c = bmp[p] | (bmp[p+1]<<8) ;										
	    
	    if ( ( x < 480) && ( y < 272) )
	        LCDBUFF[y][x] = c ;
		
	    p = p + 2 ;	
    	}
    }
}

void clearSrc(unsigned int color)
{
    TPAL = (1<<24)|(color&0xffffff);	
}
extern const unsigned char bmp[90200];
void lcd_test()
{
    int x;
    for(x=0;x<ROW;x++)
        point(x++,150,0xff0000);
   Paint_Bmp(0,0,220,220,bmp); 
}
