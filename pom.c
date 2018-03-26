#include <linux/init.h>
#include <linux/module.h>
#include <linux/delay.h>
#include <linux/kernel.h>
#include <linux/random.h>
MODULE_LICENSE("Dual BSD/GPL");

#define MINS_TO_MS(a) ((a) * 60 * 1000)

/* sleep 25 minutes +/- 5 minutes before kernel panic */
#define POM_DEFAULT_START (25)
#define POM_DEFAULT_WINDOW (10)

static int pom_init(void)
{
    int mins;
    get_random_bytes(&mins, sizeof(mins));
    mins = (mins % POM_DEFAULT_WINDOW) - (POM_DEFAULT_WINDOW >> 1);
    mins += POM_DEFAULT_START;

    msleep(MINS_TO_MS(mins));
    panic("Take a break already!");
    return 0;
}

static void pom_exit(void)
{
    printk(KERN_ALERT "Exiting\n");
}

module_init(pom_init);
module_exit(pom_exit);
