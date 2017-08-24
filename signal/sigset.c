#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <signal.h>

int main()
{

    sigset_t set,old;
    sigemptyset(&set);
    sigaddset(&set, 14);
    sigprocmask(SIG_BLOCK, &set, &old);
    while(1)
    {
        printf("a\n");
        sleep(1);
    }

    return 0;
}
