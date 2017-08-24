#include <stdio.h>
#include <unistd.h>/*fork*/
#include <stdlib.h>
#include <sys/wait.h>

int
main()
{
    pid_t pid;
    int i;
    int wpi;
    // pid_t arr[10];
    for(i=0; i<10; i++)
    {
        pid = fork();
        if(pid == 0)
            break;
        // else if(pid > 0)
        // {
        //     while(waitpid(0, NULL, WNOHANG));
        //     // arr[i] = pid;
        // }
    }
    // for(int i=0; i<10; i++)
    //     printf("%d\n",arr[i]);
    if(pid == 0)
    {
        printf("我是子进程,%d\n",getpid());
        sleep(5);
        // while(1);
    }
    if(i == 10){
        printf("我是父进程\n");
        do {
            wpi = waitpid(-1, NULL, WNOHANG);
            printf("%d\n",wpi);
            sleep(1);
        } while(wpi >= 0);
        // while( == 0);
        while(1);
    }

    return 0;
}
