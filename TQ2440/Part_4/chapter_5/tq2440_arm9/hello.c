#include <linux/init.h>
#include <linux/module.h>
MODULE_LICENSE("Dual BSD/GPL");

static int hello_init()
{
    printk(KERN_ALERT"Hello TQ2440!\n");
    return 0;	
}

static void hello_exit()
{
    printk(KERN_ALERT"Exit TQ2440!\n");	
}

module_init(hello_init);
module_exit(hello_exit);