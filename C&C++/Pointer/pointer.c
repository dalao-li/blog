/*
 * @Description:
 * @Version: 1.0
 * @Author: dalao
 * @Email:
 * @Date: 2022-04-15 18:20:02
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2024-07-01 18:35:37
 */

#include <stdio.h>

int main(void)
{
    int a = 3;
    char b = 'A';

    int *p1;
    char *p2;

    // int *p1 = a;
    p1 = &a;

    // char *p2 = b;
    p2 = &b;

    printf("a = %d &a = %x sizeof(a) = %d\n", a, &a, sizeof(a));
    printf("*p1 = %d &p1 = %x sizeof(p1) = %d\n", *p1, p1, sizeof(p1));

    printf("b = %d &b = %x sizeof(b) = %d\n", b, &b, sizeof(b));
    printf("*p2 = %d &p2 = %x sizeof(p2) = %d\n", *p2, p2, sizeof(p2));
}