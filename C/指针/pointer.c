/*
 * @Description: 
 * @Version: 1.0
 * @Author: dalao
 * @Email: dalao_li@163.com
 * @Date: 2022-04-15 18:20:02
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-15 18:20:45
 */

#include<stdio.h>

int main(void) {
    int a = 3;
    char b = 'A';

    int *p1;
    char *p2;
    
    // int *p1 = a;
    p1 = &a;

    // char *p2 = b;
    p2 = &b;

    // a = 3   &a = 1f6818a4  sizeof(a) = 4
    // *p1 = 3 &p1 = 1f6818a4 sizeof(p1) = 8
    printf("a = %d &a = %x sizeof(a) = %d\n" , a , &a , sizeof(a));
    printf("*p1 = %d &p1 = %x sizeof(p1) = %d\n" , *p1 , p1 , sizeof(p1));

    // b = A   &b = 1f6818a3  sizeof(b) = 1
    // *p2 = A &p2 = 1f6818a3 sizeof(p2) = 8
    printf("b = %d &b = %x sizeof(b) = %d\n" , b , &b , sizeof(b));
    printf("*p2 = %d &p2 = %x sizeof(p2) = %d\n" , *p2 , p2 , sizeof(p2));
}