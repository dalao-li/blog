/*
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-02-23 21:44:57
 * @LastEditors: DaLao
 * @LastEditTime: 2022-02-23 22:07:20
 */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(void){
    pid_t pid = fork();
    if(pid == 0){
        printf("a");
        fflush(stdout);
    }
    else{
        printf("b");
        fflush(stdout);
        waitpid(-1, NULL, 0);
        
    }
    printf("c");
    fflush(stdout);
    return 0;
}

// acbc
// bacc