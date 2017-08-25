#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>


int num;
pthread_rwlock_t rw;
void* read_fun(void* arg)
{
    while(1)
    {
        pthread_rwlock_rdlock(&rw);
        printf("read-------%d\n",num);
        pthread_rwlock_unlock(&rw);
        sleep(1);
    }

    return NULL;
}

void* write_fun(void* arg)
{
    while(1)
    {
        pthread_rwlock_wrlock(&rw);
        printf("---write-------%d\n",num++);
        pthread_rwlock_unlock(&rw);
        sleep(1);
    }

    return NULL;
}

int main()
{
    num = 0;
    pthread_rwlock_init(&rw,NULL);
    for(int i=0; i<3; i++)
    {
        pthread_t tid;
        pthread_create(&tid, NULL, read_fun, NULL);
    }
    for(int i=0; i<3; i++)
    {
        pthread_t tid;
        pthread_create(&tid, NULL, write_fun, NULL);
    }
    while(1)
        ;
    return 0;
}
