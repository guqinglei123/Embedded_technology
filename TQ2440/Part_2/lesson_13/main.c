

int gboot_main()
{
unsigned char buf[2048];
#ifdef MMU_ON 
    mmu_init();
#endif

    led_init();
    led_on();

    button_init();
    interupt_init();
    
    nand_Erase(64*5+1);
    buf[0]=100;
    nand_PageWrite(64*5+1,buf);
    buf[0]=10;
    nand_PageRead(64*5+1,buf);
    if(buf[0]==100)
        led_off();

    while(1);
    return 0;    
}