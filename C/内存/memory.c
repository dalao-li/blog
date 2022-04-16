/*
 * @Description: 
 * @Version: 1.0
 * @Author: dalao
 * @Email: dalao_li@163.com
 * @Date: 2022-04-16 15:17:04
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-16 15:25:28
 */

#include <stdio.h>
#include <malloc.h>

int main(void){
    // 在栈分配
    int i1 = 0;
    int i2 = 0;
    int i3 = 0;

    printf("栈:向下\n");
    printf("i1 = %x\n" , &i1);
    printf("i2 = %x\n" , &i2);
    printf("i3 = %x\n" , &i3);

    // 在堆分配
    printf("堆:向上\n");
    char *p1 = (char *)malloc(4);
    char *p2 = (char *)malloc(4);
    char *p3 = (char *)malloc(4);

    printf("p1 = %x\n" , p1);
    printf("p2 = %x\n" , p2);
    printf("p3 = %x\n" , p3);

    // 释放堆内存
    free(p1);
    p1=NULL;

    free(p2);
    p2=NULL;
    
    free(p3);
    p3=NULL;
    
    return 0;
}