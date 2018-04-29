
#define INTMSK              (volatile unsigned long*)0x4A000008
#define EINTMSK             (volatile unsigned long*)0x560000a4
#define INTOFFSET           (volatile unsigned long*)0x4A000014
#define SRCPAD              (volatile unsigned long*)0x4a000000
#define INTPAD              (volatile unsigned long*)0x4a000010
#define EINTPAND            (volatile unsigned long*)0x560000a8

void interupt_init()
{
    
    *(EINTMSK) &=  ~(1<< 4 );  //必须是在配置INTmask之前
    *(INTMSK) &= (~(1<<0))& (~(1<<1)) & (~(1<<2)) & (~(1<<4));

     __asm__(
        "mrs r0, cpsr\n"        //打开CPSR中的中断操作
        "bic r0, r0, #0x80\n"
        "msr cpsr_c, r0\n"                  
        :
        :        
     );   
}


void handle_int()
{
    unsigned long value = *(INTOFFSET);  //判断产生那个中断源是那个

    switch(value)                       //中断处理
    {
        case 1:   //k1
            led_on();
        break;

        case 4:  //k2
            led_on();
        break;

        case 2:   //k3
            led_off();
        break;

        case 0: //k4
            led_off();
        break;
        default:
        break;
    }

    *(SRCPAD) = (1 << value); //中断清除
    *(INTPAD) = (1 << value); 
    if(value == 4)
    {
        *(EINTPAND) = (1 << 4);
    }
}
