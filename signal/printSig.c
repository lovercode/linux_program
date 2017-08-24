#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <signal.h>


void printped(sigset_t* ped)
{
    int i;
    for(i=1; i<32; i++)
    {
        printf("%d",sigismember(ped,i));
    }
    printf("\n");
}

int main()
{
    sigset_t set,old,ped;
    sigemptyset(&set);
    sigfillset(&set);
    // sigaddset(&set, 3);
    sigprocmask(SIG_BLOCK, &set, &old);

    while(1)
    {
        sigpending(&ped);
        printped(&ped);
        sleep(1);
        printf("------------\n");
    }

}
