#include <linux/init.h>
#include <linux/io.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
static int __init simple_initt(void)
{
 int ret;
 void __iomem *regs;
 uint size = 0xFE000000;

 while(1)
 {
    regs = ioremap(size, 0x1000);
    iowrite32(0x12345678, regs);
    size = size +100;
 }

 return 0;
}
static void __exit simple_exitt(void)
{
}

/* initialization and exit */
module_init(simple_initt);
module_exit(simple_exitt);