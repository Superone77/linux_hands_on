#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int init_hello(void)
{
        printk("Exp03_init...\n");
        return 0;
}
static void exit_hello(void)
{
        printk("Exp03_exit...\n");
}
module_init(init_hello);
module_exit(exit_hello);

MODULE_LICENSE("GPL");  //告诉内核该模块遵循GPL协议
MODULE_AUTHOR("Tea");   //模块作者
MODULE_DESCRIPTION("Linux_Exp_03");     //模块描述
MODULE_SUPPORTED_DEVICE("ExpDevice");   //模块支持的设备
