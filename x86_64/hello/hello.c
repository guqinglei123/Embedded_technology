/*
 * a simple kernel module: hello
 *
 * Copyright (C) 2014 Barry Song  (baohua@kernel.org)
 *
 * Licensed under GPLv2 or later.
 */

#include <linux/init.h>
#include <linux/module.h>

static int __init hello_init(void)
{
	printk(KERN_ALERT "Hello Linux4.0 enter\n");
	return 0;
}
module_init(hello_init);

static void __exit hello_exit(void)
{
	printk(KERN_ALERT "Hello Linux4.0 exit\n");
}
module_exit(hello_exit);

MODULE_AUTHOR("Ni Liu <guqinglei692@gmail.com>");
MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("A simple Hello Linux4.0 Module");
MODULE_ALIAS("a simplest module");
