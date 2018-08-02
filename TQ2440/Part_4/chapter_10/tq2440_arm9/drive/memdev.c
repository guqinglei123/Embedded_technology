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
  int char mem[MEN_SIZE];
};
struct mem_dev *mem_devp;

/*文件打开函数*/
int mem_open(struct inode *inode, struct file *filp)
{

  /*获取次设备号*/
  int num = MINOR(inode->i_rdev);

  if (num == 0)
    filp->private_data = dev1_registers;
  else if (num == 1)
    filp->private_data = dev2_registers;
  else
    return -ENODEV; //无效的次设备号

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
  int *register_addr = filp->private_data; /*获取设备的寄存器基地址*/

  /*判断读位置是否有效*/
  if (p >= 5 * sizeof(int))
    return 0;
  if (count > 5 * sizeof(int) - p)
    count = 5 * sizeof(int) - p;

  /*读数据到用户空间*/
  if (copy_to_user(buf, register_addr + p, count))
  {
    ret = -EFAULT;
  }
  else
  {
    *ppos += count;
    ret = count;
  }

  return ret;
}

/*写函数*/
static ssize_t mem_write(struct file *filp, const char __user *buf, size_t size, loff_t *ppos)
{
  unsigned long p = *ppos;
  unsigned int count = size;
  int ret = 0;
  int *register_addr = filp->private_data; /*获取设备的寄存器地址*/

  /*分析和获取有效的写长度*/
  if (p >= 5 * sizeof(int))
    return 0;
  if (count > 5 * sizeof(int) - p)
    count = 5 * sizeof(int) - p;

  /*从用户空间写入数据*/
  if (copy_from_user(register_addr + p, buf, count))
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
  case SEEK_SET:
    newpos = offset;
    break;

  case SEEK_CUR:
    newpos = filp->f_pos + offset;
    break;

  case SEEK_END:
    newpos = 5 * sizeof(int) - 1 + offset;
    break;

  default:
    return -EINVAL;
  }
  if ((newpos < 0) || (newpos > 5 * sizeof(int)))
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

  /*初始化cdev结构*/
  mem_devp = kmalloc(memdev_nr_devs * sizeof(struct mem_dev), GFP_KERNEL);
  if (!mem_devp)
  {
    ret = -ENOMEM;
    goto fail; /* Make this more graceful */
  }
  memset(scull_devices, 0, scull_nr_devs * sizeof(struct scull_dev));
  cdev_init(&mem_devp->cdev, &mem_fops);
  mem_devp->cdev.owner = THIS_MODULE;

  /* 注册字符设备 */
  cdev_add(&cdev, devno, 2);

  /* 注册字符设备 */
fail:
}

/*模块卸载函数*/
static void memdev_exit(void)
{
  cdev_del(&cdev);                    /*注销设备*/
  unregister_chrdev_region(devno, 2); /*释放设备号*/
}

MODULE_LICENSE("GPL");

module_init(memdev_init);
module_exit(memdev_exit);
