/*
 * @Description:
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-02-17 23:53:18
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-11 23:06:10
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int g_var = 6;

int main(void)
{
    int var = 88;
    pid_t pid = fork();
    // 子进程修改值
    if (pid == 0)
    {
        g_var++;
        var++;
    }
    // 父进程休眠两秒, 让子进程先输出
    else
    {
        sleep(1);
    }
    printf("father pid = %ld, pid = %ld, g_var = %d, var = %d\n", getppid(), getpid(), g_var, var);
    return 0;
}