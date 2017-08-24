#include <stdio.h>
#include <stdlib.h>

extern char** environ;

/**
 * 显示所以环境变量信息
 */
void
showAll()
{
    int i = 0;
    while(environ[i])
    {
        printf("%s\n",environ[i]);
        i++;
    }
}

int
main()
{
    //设置环境变量 !0 覆盖 0 不覆盖
    setenv("PATH","qqqq",0);
    //获取环境变量
    printf("%s\n", getenv("PATH"));
    //删除不存在环境变量不会报错 删除 aa= 会报错
    unsetenv("aa");

    return 0;
}
