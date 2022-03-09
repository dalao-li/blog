#include<iostream>
#include<fstream>

using namespace std;

unsigned int getcrc32(char *s, unsigned int len) {
    unsigned int crc_table[256];
    unsigned int crc;
    for (unsigned int i = 0; i < 256; i++) {
        crc = i;
        for (unsigned int j = 0; j < 8; j++) {
            if (crc & 1){
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
        crc = (crc >> 8) ^ crc_table[index];
    }
    crc ^= 0xffffffff;
    return crc;
}

// Segmentation fault (core dumped)
// Program terminated with signal SIGSEGV, Segmentation fault.
int main(int argc , char *argv[]){
    // 打开图片文件
    ifstream is(argv[1] , ifstream::in | ios::binary);
    is.seekg(0 , is.end);
    // 获取文件流指针位置，计算图片长度
    int length = is.tellg();
    // 将文件流指针定位到流的开始
    is.seekg(0 , is.beg);
    printf("length : %d\n" , length);
    char *buffer = new char[length];
    is.read(buffer , length);
    printf("\n--- %x \n",getcrc32(buffer,length));
    delete[] buffer;
    return 0;
}
