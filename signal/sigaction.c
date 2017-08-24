#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <signal.h>


void docatch(int sig)
{
    printf("catch----------\n");
    sleep(10);
    printf("ok\n");
}
int main()
{
    struct sigaction act;
    act.sa_handler = docatch;
    act.sa_flags = 0;   //默认属性 信号捕捉期间,自动屏蔽本信号
    sigemptyset(&act.sa_mask);
    sigaddset(&act.sa_mask, SIGQUIT);
    int ret = sigaction(SIGINT, &act, NULL);
    while(1)
        ;
    return 0;
}
