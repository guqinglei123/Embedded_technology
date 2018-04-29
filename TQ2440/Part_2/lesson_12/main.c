

int gboot_main()
{

#ifdef MMU_ON 
    mmu_init();
#endif

    led_init();
    led_on();

    button_init();
    interupt_init();
    while(1);
    return 0;    
}