

int gboot_main()
{
unsigned char buf[2048];
int num;
#ifdef MMU_ON 
    mmu_init();
#endif

    led_init();
    led_on();

    button_init();
//  interupt_init();
    
    nand_Erase(64*5+1);
    buf[0]=100;
    nand_PageWrite(64*5+1,buf);
    buf[0]=10;
    nand_PageRead(64*5+1,buf);
    if(buf[0]==100)
        led_off();
    uart_init();

    while(1)
    {
    	printf("\n***************************************\n\r");
    	printf("\n*****************GBOOT*****************\n\r");
    	printf("1:Download Linux Kernel from TFTP Server!\n\r");
    	printf("2:Boot Linux from RAM!\n\r");
    	printf("3:Boor Linux from Nand Flash!\n\r");
    	printf("\n Plese Select:");
    	
    	scanf("%d",&num);
    
        switch (num)
        {
            case 1:
            printf("tftp_load()");
            //tftp_load();
            break;
            
            case 2:
            printf("boot_linux_ram()");
            //boot_linux_ram();
            break;
            
            case 3:
            printf("boot_linux_nand()");
            //boot_linux_nand();
            break;
            
            default:
                printf("Error: wrong selection!\n\r");
            break;	
        }
    	
    }
    return 0;    
}
