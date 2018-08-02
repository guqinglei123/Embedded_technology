#include <linux/module.h>
#include <linux/types.h>
#include <linux/fs.h>
#include <linux/errno.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <linux/slab.h>

#define MEN_MAJOR 230
#define MEN_NR_DEVS 2
#define MEN_SIZE 5

int memdev_major = MEN_MAJOR;
int memdev_minor = 0;
int memdev_nr_devs = MEN_NR_DEVS; /* number of bare scull devices */

module_param(memdev_major, int, S_IRUGO);
module_param(memdev_minor, int, S_IRUGO);
module_param(memdev_nr_devs, int, S_IRUGO);

struct mem_dev
{
  struct cdev cdev;
  unsigned char mem[MEN_SIZE];
};
struct mem_dev *mem_devp;

/*文件打开函数*/
int mem_open(struct inode *inode, struct file *filp)
{
  /*获取次设备号*/
  struct mem_dev *dev = container_of(inode->i_rdev,struct mem_dev,cdev);
  filp->private_data = dev;
  return 0;
}

/*文件释放函数*/
int mem_release(struct inode *inode, struct file *filp)
{
  return 0;
}

/*读函数*/
static ssize_t mem_read(struct file *filp, char __user *buf, size_t size, loff_t *ppos)
{
  unsigned long p = *ppos;
  unsigned int count = size;
  int ret = 0;
  struct mem_dev *mendev_addr = filp->private_data; /*获取设备的地址*/

  /*判断读位置是否有效*/
  if (p >= MEN_SIZE* sizeof(char))
    return 0;
  
  /*可以读取的数据长度*/
  if (count > MEN_SIZE * sizeof(char) - p)
    count = MEN_SIZE * sizeof(char) - p;

  /*读数据到用户空间*/
  if (copy_to_user(buf, mendev_addr + p, count))
  {
    ret = -EFAULT;
  }
  else
  {
    *ppos += count;
    ret = count;
    printk(KERN_INFO "read %u bytes from %lu\n", count, p);
  }

  return ret;
}

/*写函数*/
static ssize_t mem_write(struct file *filp, const char __user *buf, size_t size, loff_t *ppos)
{
  unsigned long p = *ppos;
  unsigned int count = size;
  int ret = 0;
  struct mem_dev *mendev_addr = filp->private_data; /*获取设备的寄存器地址*/

  /*判断写的位置是否有效*/
  if (p >= MEN_SIZE* sizeof(char))
    return 0;

  /*分析和获取有效的写长度*/
  if (count > MEN_SIZE* sizeof(char) - p)
    count = MEN_SIZE* sizeof(char) - p;

  /*从用户空间写入数据*/
  if (copy_from_user(mendev_addr + p, buf, count))
    ret = -EFAULT;
  else
  {
    *ppos += count;
    ret = count;
  }

  return ret;
}

/* seek文件定位函数 */
static loff_t mem_llseek(struct file *filp, loff_t offset, int whence)
{
  loff_t newpos;

  switch (whence)
  {
  case SEEK_SET://开始位置
    newpos = offset;
    break;

  case SEEK_CUR://指定位置
    newpos = filp->f_pos + offset;
    break;

  case SEEK_END://end位置
    newpos = MEN_SIZE* sizeof(char) - 1 + offset;
    break;
  default:   
    return -EINVAL;
  }
  if ((newpos < 0) || (newpos > MEN_SIZE* sizeof(char)))
    return -EINVAL;

  filp->f_pos = newpos;
  return newpos;
}

/*文件操作结构体*/
static const struct file_operations mem_fops =
    {
        .llseek = mem_llseek,
        .read = mem_read,
        .write = mem_write,
        .open = mem_open,
        .release = mem_release,
};

/*设备驱动模块加载函数*/
static int memdev_init(void)
{
  int ret;
  dev_t devno = 0;

  /* 获取字符设备号 */
  if (memdev_major)
  {
    devno = MKDEV(memdev_major, memdev_minor);
    ret = register_chrdev_region(devno, memdev_nr_devs, "scull");
  }
  else
  {
    ret = alloc_chrdev_region(&devno, memdev_minor, memdev_nr_devs,
                              "memdev");
    memdev_major = MAJOR(devno);
  }
  if (ret < 0)
  {
    printk(KERN_WARNING "memdev: can't get major %d\n", memdev_major);
    return ret;
  }

  /*分配mem_dev内存，得到mem_devp*/
  mem_devp = kmalloc(memdev_nr_devs * sizeof(struct mem_dev), GFP_KERNEL);
  if (!mem_devp)
  {
    ret = -ENOMEM;
    goto fail_malloc; /* Make this more graceful */
  }
  memset(mem_devp, 0, memdev_nr_devs * sizeof(struct mem_dev));

  int index=0;
  for (index=0;index<memdev_nr_devs;index++)//这部分可以写成一个函数,配置cdev
  {
    struct mem_dev *mem_devpp = mem_devp+index;//为什么mem_devpp = mem_devp[index]会有问题？？？
    /*初始化cdev结构*/
    cdev_init(&(mem_devpp->cdev), &mem_fops);
    mem_devpp->cdev.owner = THIS_MODULE;

    /* 注册字符设备 */
    dev_t devt = MKDEV(memdev_major, memdev_minor + index);
    int err = cdev_add(&mem_devpp->cdev, devt, 2);
    if (err)
      printk(KERN_NOTICE "Error %d adding memdev%d", err, index);
  }

fail_malloc:
  unregister_chrdev_region(devno, memdev_nr_devs);
  return ret;
}
module_init(memdev_init);

/*模块卸载函数*/
static void memdev_exit(void)
{
  dev_t devt = MKDEV(memdev_major, memdev_minor);

  if(mem_devp)
  {
    int index=0;
    struct mem_dev *mem_devpp = mem_devp+index;
    for (index=0;index<memdev_nr_devs;index++)
      cdev_del(&mem_devpp->cdev);  /*注销设备*/
    kfree(mem_devp);    
  }

  unregister_chrdev_region(devt, memdev_nr_devs); /*释放设备号*/
}
module_exit(memdev_exit);
MODULE_AUTHOR("guqinglei962@gmail.com,NI LIU");
MODULE_LICENSE("GPL");



