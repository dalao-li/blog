<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email:  
 * @Date: 2022-08-14 01:23:03
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2024-06-10 18:32:21
-->

# FILE

## 定义

```c++
#ifndef _FILE_DEFINED
struct _iobuf {
    // 文件输入的下一个位置
    char *_ptr;
    // 当前缓冲区的相对位置
    int _cnt;
    // 文件起始位置
    char *_base;
    // 文件标志
    int _flag;
    // 文件描述符id
    int _file;
    // 检查缓冲区状况,如果无缓冲区则不读取
    int _charbuf;
    // 文件缓冲区大小
    int _bufsiz;
    // 临时文件名
    char *_tmpfname;
};

typedef struct _iobuf FILE;

#define _FILE_DEFINED
#endif
```

FILE结构是间接地操作系统的文件控制块(FCB)来实现对文件的操作

## 接口

### fopen

```c
// 打开文件.读文件到内存.返回文件信息结构指针
FILE *fopen(char *file, char *open_mode)
``
