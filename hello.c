#include <linux/module.h>       /* Needed by all modules */
#include <linux/kernel.h>       /* Needed for KERN_INFO */
#include <linux/init.h>         /* Needed for the macros */
#include <linux/moduleparam.h> 
#include <linux/stat.h>  
#define DRIVER_AUTHOR "Big dick man / bigdickomano@gmail.com"
#define DRIVER_DESC   "A sample driver"

MODULE_AUTHOR(DRIVER_AUTHOR);

static short int myshort = 1;
static int myint = 420;
static long int mylong = 9999;
static char *mystring = "blah";
static int myintArray[2] =  {-1,-1 };
static int arr_argc = 0;

module_param(myshort, short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(myshort, "A short integer");
module_param(myint, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(myint, "An integer");
module_param(mylong, long, S_IRUSR);
MODULE_PARM_DESC(mylong, "A long integer");
module_param(mystring, charp, 0000);
MODULE_PARM_DESC(mystring, "A character string");

module_param_array(myintArray, int, &arr_argc, 0000);
MODULE_PARM_DESC(myintArray, "An array of integers");

static int __init init_hello(void)
{
       int i;
       printk(KERN_INFO "Hello, world");
       printk(KERN_INFO "myshort is a short integer: %hd", myshort);
       printk(KERN_INFO "myint is an integer: %d\n", myint);        
       printk(KERN_INFO "mylong is a long integer: %ld\n", mylong);        
       printk(KERN_INFO "mystring is a string: %s\n", mystring);
       for (i=0; i  < (sizeof myintArray / sizeof (int)); i++)
       {
        printk(KERN_INFO "myintArray[%d] = %d\n", i, myintArray[i]);  
       }
       printk(KERN_INFO "got %d arguments for myintArray.\n", arr_argc);
       return 0;
}
static void __exit cleanup_hello(void)
{
       printk(KERN_INFO "Googbye, world");
}
module_init(init_hello);
module_exit(cleanup_hello);
MODULE_LICENSE("GPL");



