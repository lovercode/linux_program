## socket编程
### 网络字节序
<pre>
    IP:本地-->网络字节序(inet_pton())
    IP:网络字节序-->本地(inet_ntop())
</pre>


### sockaddr数据结构
<pre>
    sockaddr_in 但是传给bind,accept,connect需要强制转换成sockaddr
</pre>
