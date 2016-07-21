#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>//class_create

#define SX_MAJOR         285
#define SX_MINOR         1

static struct class *sx_class;
static struct device *sx_device;
struct Sx_dev
{
	struct cdev cdev;
};
struct Sx_dev *sx_dev;
int sx_open(struct inode *inode, struct file *filp)
{
	printk("open success!\n");
	return 0;
}

int sx_close(struct inode *inode, struct file *filp)
{
	printk("close success!\n");
	return 0;
}

static const struct file_operations sx_fops =
{
	.owner = THIS_MODULE,
	.open =  sx_open,
	.release = sx_close,
};//do not fogit the ;
static int sx_dev_init(void)
{
	dev_t dev_num;
	int ret;
	dev_num = MKDEV(SX_MAJOR, 0);
	ret = register_chrdev_region(dev_num, 1, "sx_dev5");
	if(ret < 0)
	{
		printk("register num failed!\n");
	}
	else
	{
		printk("register num success!\n");
	}
	
	sx_dev = cdev_alloc();
	cdev_init(&sx_dev->cdev, &sx_fops);
	sx_dev->cdev.owner = THIS_MODULE;
	sx_dev->cdev.ops   = &sx_fops;
	
	ret = cdev_add(&sx_dev->cdev, dev_num, 1);
	if(ret)
	{
		printk("cdev_add error!\n");
	}
	else
	{
		printk("success!\n");
	}

	/**/
	sx_class = class_create(THIS_MODULE, "sx_dev");
	sx_device = device_create(sx_class, NULL, dev_num, NULL, "sx_ccore");

	return 0;
}

static void sx_dev_exit(void)
{
	cdev_del(&sx_dev->cdev);
	unregister_chrdev_region(MKDEV(SX_MAJOR, 0), 1);
}
module_init(sx_dev_init);
module_exit(sx_dev_exit);

MODULE_AUTHOR("sx");
MODULE_DESCRIPTION("I love ccore!");
MODULE_LICENSE("GPL");

