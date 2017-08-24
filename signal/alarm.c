#include <stdio.h>
#include <unistd.h>
int main()
{
    int i = 1;
    alarm(1);
    while(i++)
        printf("%d\n",i);
    return 0;
}
