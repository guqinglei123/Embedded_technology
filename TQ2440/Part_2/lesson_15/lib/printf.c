#include "vsprintf.h"

unsigned char outbuf[1024];
unsigned char inbuf[1024];

int printf(const char* fmt, ...)
{
    int i;
    va_list args;

    //1.将变参数转换为字符串
    va_start(args,fmt);
    vsprintf((char *)outbuf,fmt,args);
    va_end();

    //打印字符串到串口
    for (i = 0; i < strlen((char*)outbuf);i++)
    {
        putc(outbuf[i]);
    }
}

int scanf(const char* fmt, ...)
{
    unsigned char c;
    va_list args;
    int i = 0;
    //获得输入的字符串
     while(1)
    {
        c = getc();
        if((c == 0x0d)||(c == 0x0a))
        {
            inbuf[i] = '/n';
            break;
        }
        else
        {
            inbuf[i++] = c;
        }
    }

    //将变参数转换为字符串
    va_start(args,fmt);
    vsscanf((char *)inbuf,fmt,args);
    va_end(args);

    return i;

}

/*int scanf(const char* fmt, ...)
{
	unsigned char c;
	int i = 0;
	va_list args;
	
	//1. 获取输入的字符串
	
	while (1)
	{
		
	    c = getc();	
	    if ((c==0x0d) || (c==0x0a))
	    {
	    	inbuf[i] = '\n';
	    	break;
	    }
	    else
	    {
	        inbuf[i++] = c;	
	    }
	}
	
	//2. 格式转化
	va_start(args, fmt);
	vsscanf((char *)inbuf,fmt,args);
	va_end(args);
	
	return i;
}*/