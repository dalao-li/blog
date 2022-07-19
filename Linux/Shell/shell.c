/*
 * @Description:
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-02-24 21:48:26
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-05 14:13:52
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

const int MAXLINE = 100;
const int MAXARGS = 10;

extern char **environ;

// 解释shell输入行
int parseline(char *buf, char **argv)
{
    char *delim;
    int argc;
    int bg;

    buf[strlen(buf) - 1] = ' ';
    while (*buf && (*buf == ' '))
    {
        buf++;
    }

    argc = 0;

    while ((delim == strchr(buf, ' ')))
    {
        argv[argc++] = buf;
        *delim = '\0';
        buf = delim + 1;
        while (*buf && (*buf == ' '))
        {
            buf++;
        }
    }
    argv[argc] = NULL;
    if (argc == 0)
    {
        return 1;
    }
    if ((bg = (*argv[argc - 1] == '&')) != 0)
    {
        argv[--argc] = NULL;
    }

    return bg;
}

int builtin_command(char **argv)
{
    if (!strcmp(argv[0], "quit"))
    {
        exit(0);
    }
    if (!strcmp(argv[0], "&"))
    {
        return 1;
    }
    return 0;
}

void eval(char *cmdline)
{
    char *argv[MAXARGS];
    char buf[MAXLINE];
    int bg;
    pid_t pid;

    strcpy(buf, cmdline);
    bg = parseline(buf, argv);
    if (argv[0] == NULL)
    {
        return;
    }
    if (!builtin_command(argv))
    {
        pid = fork();
        if (pid == 0)
        {
            if (execve(argv[0], argv, environ) < 0)
            {
                printf("%s: command not found.\n", argv[0]);
            }
        }
        if (!bg)
        {
            int status;
            if (waitpid(pid, &status, 0) < 0)
            {
                exit(0);
            }
        }
        else
        {
            printf("%d %s\n", pid, cmdline);
        }
    }
}

int main(int argc, char *argv[])
{
    char cmdline[MAXLINE];
    while (1)
    {
        printf("> ");
        fgets(cmdline, MAXLINE, stdin);
        if (feof(stdin))
        {
            exit(0);
        }
        eval(cmdline);
    }
}