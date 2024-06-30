/*
 * @Description:
 * @Version: 1.0
 * @Author: DaLao
 * @Email:  
 * @Date: 2022-02-14 18:21:47
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-17 09:28:17
 */

#include <stdio.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

const int MAXLINE = 100;

int main(void)
{
    char buf[MAXLINE];
    pid_t pid;
    int status;
    while (fgets(buf, MAXLINE, stdin) != NULL)
    {
        if (buf[strlen(buf) - 1] == '\n')
        {
            buf[strlen(buf) - 1] = 0;
        }
        pid = fork();
        if (pid < 0)
        {
            printf("error");
            exit(127);
        }
        if (pid == 0)
        {
            execlp(buf, buf, (char *)0);
            printf("can not execute :%s\n", buf);
            exit(127);
        }
        pid = waitpid(pid, &status, 0);
        if (pid < 0)
        {
            printf("waitpid error");
        }
    }
    return 0;
}