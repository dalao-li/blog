/*
 * @Description: Zlib样例
 * @Version: 1.0
 * @Author:
 * @Email:
 * @Date: 2023-12-14 22:05:49
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2023-12-15 23:17:35
 */

#include "zlib.h"

#include <stdio.h>
#include <string.h>

const int MAX_LEN = 100 * 1024;

int main(void)
{
    // 存放读取文件数据
    char buffer[MAX_LEN] = {'\0'};
    FILE *fp;

    fp = fopen("Demo.txt", "r");
    if (fp == NULL)
    {
        perror("open file fail!");
        exit(0);
    }

    fread(buffer, sizeof(buffer), sizeof(char), fp);

    // 源文件长度
    uLong srcLen = strlen(buffer) + 1;

    // 压缩文件长度
    uLong dstLen = MAX_LEN;
    // 存放压缩后数据
    Bytef dst[MAX_LEN] = {'\0'};

    int res = compress(dst, &dstLen, (const Bytef *)buffer, srcLen);

    // 生成压缩文件
    fp = fopen("Compress", "w");
    fwrite(dst, strlen((char *)dst), 1, fp);

    // 解压文件长度
    uLong srcExLen = MAX_LEN;
    char srcEx[MAX_LEN] = {'\0'};

    res = uncompress((Bytef *)srcEx, &srcExLen, dst, dstLen);

    fp = fopen("UnComporess.txt", "w");
    fwrite(srcEx, strlen(srcEx), 1, fp);

    fclose(fp);

    return 0;
}