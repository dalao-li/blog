/*
 * @Description: 
 * @Version: 1.0
 * @Author: dalao
 * @Email: dalao_li@163.com
 * @Date: 2022-04-15 18:50:00
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-15 18:54:32
 */

#include<stdio.h>

int main() {
    int x = 3;
    int y = 9;

    x <<= 2;
    y >>= 1;
    
    printf("x = %d y = %d\n" , x , y);
    int a = x & y;
    int b = x | y;
    int c = x ^ y;

    printf("x & y = %d\nx | y = %d\nx ^ y = %d\n" , a , b , c);
    return 0;
}