/*
 * @Description: 
 * @Version: 1.0
 * @Author: dalao
 * @Email: dalao_li@163.com
 * @Date: 2022-04-06 22:47:55
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-07 22:59:50
 */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void) {
    // fd1 输出
    int length = write(1 , "Here is some data\n" , 17);
    if(length != 18) {
        write(2 , "A write error has occurred on file descriptor 1\n" , 46);
    }
    return 0;
}