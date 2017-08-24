#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int
main()
{
    pid_t tmp;
    int i = 0;
    for(i=0; i<5; i++)
    {
        pid_t pid = fork();
        if(pid == 0)
            break;
        if(i == 2)
            tmp = pid;
    }
    printf("my%d,%d,%d,%d\n",getpid(),i,getppid(),i<5);
    if(i != 5)
    {
        printf("子进程\n");
        while(1)
        {

            printf("child%d\n",getpid());
            sleep(1);
        }
    }
    // printf("杀死3%d",getpid());
     if(i == 5)
    {
        // sleep(3);
        printf("杀死3%d\n",getpid());
        kill(tmp, SIGKILL);
        while(1);
    }
    return 0;
}
