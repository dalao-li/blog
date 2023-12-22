/*
 * @Description: 验证字符数组长度
 * @Version: 1.0
 * @Author: dalao
 * @Email: dalao@xxx.com
 * @Date: 2022-04-15 18:41:27
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2023-12-15 22:53:58
 */

#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[1024] = {'\0'};
    // buffer sizeof = 1024, buffer strlen = 0
    printf("buffer sizeof = %d, buffer strlen = %d\n", sizeof(buffer), strlen(buffer));

    memset(buffer, 'A', 100);

    printf("buffer sizeof = %d, buffer strlen = %d\n", sizeof(buffer), strlen(buffer));

    return 0;
}