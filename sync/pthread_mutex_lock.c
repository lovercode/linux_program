#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
char buf[1024];
pthread_mutex_t mutex;


void* fun(void* arg)
{
    while(1)
    {
        pthread_mutex_lock(&mutex);
        printf("hello");

        printf(",world\n");
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }

    return NULL;
}
int main()
{
    pthread_t pid;
    pthread_mutex_init(&mutex, NULL); //mutex1

    pthread_create(&pid, NULL, fun, NULL);
    while(1)
    {
        pthread_mutex_lock(&mutex);
        printf("HELLO");

        printf(",WORLD\n");
        // pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    pthread_mutex_destroy(&mutex);
    return 0;
}
