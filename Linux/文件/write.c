/*
 * @Description:
 * @Version: 1.0
 * @Author: dalao
 * @Email: dalao_li@163.com
 * @Date: 2022-04-06 22:47:55
 * @LastEditors: DaLao
 * @LastEditTime: 2022-07-03 16:05:52
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    // 向fd1(屏幕)写入
    int length = write(STDOUT_FILENO, "Here is some data\n", 17);
    if (length != 18)
    {
        write(STDERR_FILENO, "A write error has occurred on file descriptor 1\n", 46);
    }
    return 0;
}