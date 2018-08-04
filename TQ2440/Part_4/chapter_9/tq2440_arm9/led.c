#include <linux/module.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/io.h>
// #include <mach/gpio-bank-k.h>
#include "led.h"

#define LEDCON 0x7f008800
#define LEDDAT 0x7f008808
unsigned int *led_config; 
unsigned int *led_data; 

struct cdev cdev;//描述字符设备的结构体
dev_t devno;//设备号

int led_open(struct inode *node, struct file *filp)
{
	led_config = ioremap(LEDCON,4);
	writel(0x11110000,led_config);
	
	led_data = ioremap(LEDDAT,4);
	
	return 0;
}

long led_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	switch (cmd)
	{
	    case LED_ON:
	        writel(0x00,led_data);
	        return 0;
	    
	    case LED_OFF:
	        writel(0xff,led_data);
	        return 0;
	    
	    default:
	    	return -EINVAL;
	}
}
//与虚拟文件系统的接口
static struct file_operations led_fops =
{
    .open = led_open,
    .unlocked_ioctl = led_ioctl,
};

//加载函数
static int led_init()
{
    cdev_init(&cdev,&led_fops);//将字符设备的结构体与file_operations
    
    alloc_chrdev_region(&devno, 0 , 1 , "myled");
    cdev_add(&cdev, devno, 1);//获得设备号
    
    return 0;	
}
//退出函数
static void led_exit()
{
	cdev_del(&cdev);
	unregister_chrdev_region(devno,1);
}


module_init(led_init);
module_exit(led_exit);


MODULE_AUTHOR("guqinglei962@gmail.com,NI LIU");
MODULE_LICENSE("GPL");
