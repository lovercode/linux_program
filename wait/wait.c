#include <stdio.h>
#include <unistd.h>/*fork*/
#include <stdlib.h>
#include <sys/wait.h>
int
main()
{
    int status;
    pid_t ret = fork();
    //父进程返回子进程id
    if(ret > 0)
    {
        wait(&status);
        //正常退出状态
        if(WIFEXITED(status))
            printf("%d\n", WEXITSTATUS(status));
        //退出信号
        if(WIFSIGNALED(status))
            printf("%d\n", WTERMSIG(status));

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
        while(1)
        {
            sleep(1);
            printf("--------child die-----------\n");
        }


    }
    return 13;
}
