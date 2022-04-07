/*
 * @Description: 
 * @Version: 1.0
 * @Author: dalao
 * @Email: dalao_li@163.com
 * @Date: 2022-04-07 22:58:19
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-07 22:59:20
 */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void) {
    char buffer[128];
    int nread;
    int nwrite;
    // fd0(键盘)输入
    nread = read(0 , buffer , 128);
    
    if(nread == -1) {
        write(2 , "A read error has occurred\n" , 26);
    }
    // fd1(屏幕)输出
    nwrite = write(1 , buffer , nread);
    if(nwrite != nread) {
        write(2 , "A write error has occurred\n" , 27);
    }
    return 0;
}