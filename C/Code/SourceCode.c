/*
 * @Description: 
 * @Version: 1.0
 * @Autor: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2019-07-24 23:20:17
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-10 22:14:26
 */

#include <stdio.h>

int main() {
    FILE *fp;
    char c;
    fp = fopen(__FILE__ , "r");
    do {
        c = getc(fp);
        putchar(c);
    } while (c != EOF);
    fclose(fp);
    return 0;
}
