### 多路IO
<pre>
    让内核完成监听和接受数据,让服务端程序不阻塞等待,提高效率
</pre>


### select



### epoll
<pre>
    修改打开文件的上限,
        socket描述符上限:
            /proc/sys/fs/file-max
        打开文件上限:
            etc/security/limits.conf
</pre>

<pre>
    /**
     * 返回一颗红黑树树根
     * @param __size 树大小(建议内核大小)
     */
    // epoll_create(int __size)

    /**
     * 对树进行增删改
     * @param __epfd  [description]
     * @param __op    操作 EPOLL_CTL_ADD/MOD/DEL
     * @param __fd    问件描述符
     * @param __event EPOLLIN/OUT/ERR
     */
    // epoll_ctl(int __epfd, int __op, int __fd, struct epoll_event *__event)

    /**
     * [epoll_wait description]
     * @param __epfd      树根
     * @param __events    数组(传出参数)
     * @param __maxevents 数组大小
     * @param __timeout   超时 -1阻塞
     */
    // epoll_wait(int __epfd, struct epoll_event *__events, int __maxevents, int __timeout)

</pre>

<pre>   
    边沿触发:socket有数据时触发一次,之后不再触发
    水平触发:socket有数据就会触发,直到缓冲区没有数据
</pre>

#### 边沿触发+非阻塞IO
<pre>
    边沿触发时,设置socket的非阻塞读取模式,fctl函数,效率更高
</pre>


### epoll反应堆
<pre>
    epoll:  服务器-->监听-->fd-->可读-->epoll返回-->read-->write-->epoll继续监听
    epoll反应堆:   
        1)服务器-->监听-->cfd-->可读-->epoll返回-->read-->cfd从树上摘下-->重新设置监听cfd,修改操作-->执行服务端处理代码-->等待epoll_wait返回-->回写-->重新设置cfd可读事件
        2)ep[i].date.fd换成void* ptr

</pre>
