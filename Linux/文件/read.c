/*
 * @Description:
 * @Version: 1.0
 * @Author: dalao
 * @Email: dalao@xxx.com
 * @Date: 2022-04-07 22:58:19
 * @LastEditors: DaLao
 * @LastEditTime: 2022-07-09 23:36:54
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    char buffer[128];
    int nread;
    int nwrite;
    // fd0(键盘)输入
    nread = read(STDIN_FILENO, buffer, 128);
    if (nread == -1)
    {
        write(STDERR_FILENO, "A read error has occurred\n", 26);
    }
    // fd1(屏幕)输出
    nwrite = write(STDOUT_FILENO, buffer, nread);
    if (nwrite != nread)
    {
        write(STDERR_FILENO, "A write error has occurred\n", 27);
    }
    return 0;
}