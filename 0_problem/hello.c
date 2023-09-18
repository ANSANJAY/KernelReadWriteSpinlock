#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>   
#include <linux/proc_fs.h>
#include <asm/uaccess.h>
#include <linux/mutex.h>
#include <linux/delay.h>
 
 
MODULE_LICENSE("GPL");

DEFINE_MUTEX(mylock);
 
static struct proc_dir_entry *dir_entry;
int counter = 0;

static ssize_t mywrite(struct file *file, const char __user *ubuf,size_t count, loff_t *ppos) 
{
	mutex_lock(&mylock);
	pr_info("write handler\n");
	msleep(5000);
	counter++;
	mutex_unlock(&mylock);
	return count;
}
 
static ssize_t myread(struct file *file, char __user *ubuf,size_t count, loff_t *ppos) 
{
	mutex_lock(&mylock);
	pr_info("read handler:%d\n", counter);
	msleep(10000);
	mutex_unlock(&mylock);
	return 0;
}
 
static struct file_operations proc_ops = 
{
	.owner = THIS_MODULE,
	.read = myread,
	.write = mywrite,
};
 
static int proc_init(void)
{
	dir_entry=proc_create("ldd",0666,NULL,&proc_ops);
	if (!dir_entry) {
		pr_err("%s: error creating proc_entry\n", __func__);
		return -1;
	}
        pr_info("ldd proc entry created\n");
	return 0;
}
 
static void proc_cleanup(void)
{
	remove_proc_entry("ldd", NULL);
}
 
module_init(proc_init);
module_exit(proc_cleanup);
