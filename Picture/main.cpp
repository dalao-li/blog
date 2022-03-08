/*
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-03-08 21:22:04
 * @LastEditors: DaLao
 * @LastEditTime: 2022-03-08 21:25:29
 */

#include<iostream>
#include<fstream>

using namespace std;

unsigned int getCrc32(unsigned char *s, unsigned int len) {
    unsigned int CRC32Table[256];
    unsigned int i,j;
    unsigned int CRC;
    for (i = 0; i < 256; i++) {
        CRC = i;
        for (j = 0; j < 8; j++) {
            if (CRC & 1)
                CRC = (CRC >> 1) ^ 0xEDB88320;
            else
                CRC >>= 1;
        }
        CRC32Table[i] = CRC;
    }
    CRC = 0xffffffff;
    for (unsigned int m = 0; m < len; m++) {
        CRC = (CRC >> 8) ^ CRC32Table[(CRC & 0xFF) ^ s[m]];
    }
    
    CRC ^= 0xFFFFFFFF;
    return CRC;
}

int main(){
    ifstream is("a.png" , ifstream::in | ios::binary);
    is.seekg(0 , is.end);
    int length = is.tellg();
    is.seekg(0 , is.beg);
    printf("length : %d\n" , length);
    char *buffer = new char[length];
    is.read(buffer , length);
    for(int i = 0; i < length; i++){
        printf("%x" , buffer[i]);
    }
    printf("\n\n%s\n" , buffer);
    delete[] buffer;
    return 0;
}
