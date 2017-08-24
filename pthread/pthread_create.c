#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
void* fun(void* arg)
{
    while(1)
    {
        printf("+++++++++\n");
        sleep(1);
    }
    return NULL;
}

int main()
{
    pthread_t thread;
    pthread_create(&thread, NULL, fun, NULL);
    while(1)
    {
        printf("----------\n");
        sleep(1);
    }
    return 0;
}
