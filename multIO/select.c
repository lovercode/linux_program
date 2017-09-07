#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/select.h>

int main()
{
    /**
     * [select description]
     * @param __nfds      所监听的所以文件描述符中最大的文件描述符+1
     * @param __readfds   所监听的文件描述符可读事件
     * @param __writefds  所监听的文件描述符可写事件
     * @param __exceptfds 所监听的文件描述符异常事件
     * @param __timeout   超时
     * return 返回所有的监听集合中满足条件的总数
     */
    // select(int __nfds, fd_set *restrict __readfds, fd_set *restrict __writefds, fd_set *restrict __exceptfds, struct timeval *restrict __timeout)
    select(int __nfds, fd_set *restrict __readfds, fd_set *restrict __writefds, fd_set *restrict __exceptfds, struct timeval *restrict __timeout)
    // FD_ZERO(fdsetp)  清空set
    // FD_CLR(fd, fdsetp)   清除set中的fd
    // FD_SET(fd, fdsetp)   设置fd到set
    // FD_ISSET(fd, fdsetp) 判断
}
