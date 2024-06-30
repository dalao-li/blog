/*
 * @Description:
 * @Version: 1.0
 * @Author: DaLao
 * @Email:  
 * @Date: 2022-02-20 22:56:37
 * @LastEditors: DaLao
 * @LastEditTime: 2022-02-20 23:10:25
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void sig_usr(int signo)
{
    if (signo == SIGUSR1)
    {
        printf("received SIGUSER1\n");
    }
    else if (signo == SIGUSR2)
    {
        printf("received SIGUSER2\n");
    }
    else
    {
        printf("received signal %d\n", signo);
    }
}

int main(int argv, char *argc[])
{
    if (signal(SIGUSR1, sig_usr) == SIG_ERR)
    {
        perror("can't catch SIGUSR1");
    }
    if (signal(SIGUSR2, sig_usr) == SIG_ERR)
    {
        perror("can't catch SIGUSR2");
    }
    for (;;)
    {
        pause();
    }
    return 0;
}