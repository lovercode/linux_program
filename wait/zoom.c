#include <stdio.h>
#include <unistd.h>/*fork*/
#include <stdlib.h>

int
main()
{

    pid_t ret = fork();
    //父进程返回子进程id
    if(ret > 0)
    {
        while(1)
        {
            printf("%s,%d,父:%d\n",
            "我是父进程",
            getpid(),
            ret);
            sleep(1);
        }

    }
    //子进程返回0
    else if(ret == 0)
    {

        printf("%s,%d,父:%d\n",
        "我是子进程",
        getpid(),
        getppid());
        sleep(3);
        printf("--------child die-----------\n");

    }
    return 0;
}
