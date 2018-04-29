#include <linux/init.h>
#include <linux/module.h>
MODULE_LICENSE("Dual BSD/GPL");

static int hello_init()
{
    printk(KERN_ALERT"Hello world!\n");
    return 0;	
}

static void hello_exit()
{
    printk(KERN_ALERT"hello exit!\n");	
}

module_init(hello_init);
module_exit(hello_exit);