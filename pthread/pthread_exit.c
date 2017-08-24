#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* fun(void* arg)
{
    printf("child------------\n");
    return NULL;
}

int main()
{
    pthread_t pid;
    pthread_create(&pid, NULL, fun, NULL);
    printf("main++++++++++++\n");
    //退出主控线程
    pthread_exit((void*)1);
    // return 0;
}
