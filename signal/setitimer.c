#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

unsigned int my_alarm(unsigned int sec)
{
    struct itimerval it, old;
    it.it_interval.tv_sec = 0; //设置定时秒数
    it.it_interval.tv_usec = 0;
    it.it_value.tv_sec = sec;
    it.it_value.tv_usec = 0;
    setitimer(ITIMER_REAL, &it, &old);
    return old.it_value.tv_sec;
}

int main()
{
    my_alarm(1);
    for(int i=0; ; i++)
    {
        printf("%d\n",i);
    }

    return 0;
}
