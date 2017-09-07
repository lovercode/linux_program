#include <stdio.h>
#include <unistd.h>/*fork*/
#include <linux/sched.h>
int
main()
{

    pid_t ret = fork();
    //父进程返回子进程id
    if(ret > 0)
    {
        printf("%s,%d,父:%d\n",
        "我是父进程",
        getpid(),
        getppid());
    }
    //子进程返回0
    else if(ret == 0)
    {
        // struct task_struct* task = current;

        printf("%s,%d,父:%d\n",
        "我是子进程",
        getpid(),
        getppid());
    }
    return 0;
}
