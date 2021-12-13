/*
 * @Description: 
 * @Version: 1.0
 * @Autor: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2019-07-24 23:20:17
 * @LastEditors: DaLao
 * @LastEditTime: 2021-11-27 00:27:40
 */

#include <stdio.h>
int main()
{
	FILE *fp;
	char c;
	fp = fopen(__FILE__,"r");
	do{
		c = getc(fp);
		putchar(c);
	} while (c != EOF);
	fclose(fp);
	return 0;
}
