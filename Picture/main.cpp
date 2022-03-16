/*
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-03-10 22:20:04
 * @LastEditors: DaLao
 * @LastEditTime: 2022-03-14 21:42:43
 */
#include<iostream>
#include<fstream>

using namespace std;

unsigned int get_crc32(char *s , unsigned int len) {
    unsigned int crc_table[256];
    unsigned int crc;
    for (unsigned int i = 0; i < 256; i++) {
        crc = i;
        for (unsigned int j = 0; j < 8; j++) {
            if (crc & 1){
                // 0xEDB88320= reverse 0x04C11DB7
                crc = (crc >> 1) ^ 0x04c11db7;
            }
            else{
                crc >>= 1;
            }
        }
        crc_table[i] = crc;
    }
    crc = 0xffffffff;
    for (unsigned int k = 0; k < len; k++) {
        unsigned int index = (crc ^ (unsigned char)s[k]) & 0xff;
        // 一次消掉8个字节
        crc = (crc >> 8) ^ crc_table[index];
    }
    crc ^= 0xffffffff;
    return crc;
}

unsigned int g_crc32(char *s , unsigned int len)
{
    unsigned int crc = 0xffffffff;        // Initial value
    while(len--)
    {
        crc ^= *s++;                // crc ^= *data; data++;
        for (int i = 0; i < 8; ++i)
        {
            if (crc & 1)
                crc = (crc >> 1) ^ 0xEDB88320;// 0xEDB88320= reverse 0x04C11DB7
            else
                crc = (crc >> 1);
        }
    }
    return ~crc;
}

int main(int argc , char *argv[]){
    // open file
    ifstream is(argv[1] , ifstream::in | ios::binary);
    if(!is){
        printf("open file fail!\n");
        exit(0);
    }
    // 获取文件流指针位置，计算图片长度
    is.seekg(0 , is.end);
    // 读取输入流中文件指针的位置
    int length = is.tellg();
    // 将文件流指针定位到流的开始
    is.seekg(0 , is.beg);
    char *buffer = new char[length];
    // 从输入流中提取n个字符，存数组中
    is.read(buffer , length);
    unsigned int c = g_crc32(buffer , length);
    unsigned int crc32 = get_crc32(buffer , length);
    printf("crc32 = %x \nc = %x\n" , crc32,c);
    
    delete[] buffer;
    is.close();

    return 0;
}
