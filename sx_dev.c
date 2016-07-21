#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>

static int sx_dev_init(void)
{
	return 0;
}

static void sx_dev_exit(void)
{
	
}

module_init(sx_dev_init);
module_exit(sx_dev_exit);

MODULE_AUTHOR("sx");
MODULE_DESCRIPTION("I love ccore!");
MODULE_LICENSE("GPL");

