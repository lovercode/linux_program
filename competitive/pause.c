#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
void catchAlarm(int sig)
{

}



unsigned int mysleep(unsigned int sec)
{
    struct sigaction act, old;
    act.sa_handler = catchAlarm;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    sigaction(SIGALRM, &act, &old);

    alarm(sec);
    //若此时程序失去cpu,
    //并且长时间得不到cpu,
    //过了sec时间后才获得cpu,
    //程序将处于永久的挂起状态,无法被唤醒
    //时序竞态
    /**
     * 解决:
     * 把alarm和pause组成一个原子操作
     */
    pause();


    sigaction(SIGALRM, &old, NULL);
    return alarm(0);
}

int main()
{

    while(1)
    {
        mysleep(1);
        printf("-------------\n");
    }

    return 0;
}
