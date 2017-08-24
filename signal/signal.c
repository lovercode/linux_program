#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <signal.h>


void myfun(int signo)
{
    printf("hello world\n");
}

int main()
{
    //注册SIGALERM信号的捕捉函数
    signal(SIGALRM, myfun);
    // alarm(12);
    while(1)
    {
        printf("a\n");
        sleep(1);
    }
}
