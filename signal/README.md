### 信号
<pre>
    软中断
    延时性
    内核发送,内核处理

</pre>

<pre>
    阻塞态信号集(信号屏蔽字)
    没有处理的信号(未决信号集)
    未决信号集和信号屏蔽字都在pcb中
    格式:信号编号 : 值(0或1)    
</pre>

### 未决信号集
<pre>
    产生和递达之间的状态,主要是信号屏蔽字导致的
    未决信号集合在信号产生后迅速由内核递达和处理,时间非常短暂
</pre>

### 信号屏蔽字
<pre>
    信号屏蔽字在信号产生后不会马上递达处理,信号屏蔽字影响未决信号集
</pre>

### 处理信号
<pre>
    默认处理
    忽略(丢弃)
    捕获(调用用户函数)
</pre>

### 信号四要素
<pre>
    信号名字
    信号编号
    默认处理动作
        终止进程
        忽略,比如:子进程死亡,内核会发送信号给父进程,父进程会忽略
        终止进程,产生core文件,gdb调试
        停止(暂停)
        继续
    信号事件
</pre>

### 特殊信号,不允许忽略和捕捉,只能执行默认动作,不能设置为阻塞
<pre>
    9  SIGKILL
    19 SIGSTOP
</pre>

### alarm函数
<pre>
    设置定时器,指定时间一到,内核会给当前进程发送14(SIGALRM)信号,默认动作终止
    每个进程只有一个定时器
    返回值:之前闹钟定时剩余的时间
    alarm(0) : 关闭闹钟
    与进程状态无关,无论何种状态,时间一到都会发送信号

</pre>


### setitimer
<pre>
    setitimer(__itimer_which_t __which, const struct itimerval *restrict __new, struct itimerval *restrict __old)
        __which : 指定定时方式,
            1,自然定时 ITIMER_REAL SIGALRM
            2,虚拟空间计时,(用户空间) ITIMER_VIRTUAL SIGVTALRM
            3,运行时计时(用户+内核) ITIMER_PROF 计算占用cpu和系统调用时间 SIGPROF
        __new :
</pre>


### sigaction
<pre>
    阻塞信号不支持排队,多次信号只处理一次
</pre>
