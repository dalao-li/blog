<!--
 * @Description: 
 * @Version: 1.0
 * @Author: dalao
 * @Email: dalao@xxx.com
 * @Date: 2022-04-07 23:26:04
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2023-04-05 02:11:02
-->


# 系统调用


### write


write把缓冲区buf的前nbytes个字节写入到与文件描述符fd关联的文件中, 返回实际写入的字节数

```c
size_t write(int fildes, const void *buf, size_t nbytes)
```

| 状态       | 返回值           |
| ---------- | ---------------- |
| 正常写入   | 实际写入的字节数 |
| 未写入数据 | 0                |
| 调用错误   | -1               |


```c
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void) {
    // 向fd1(屏幕)写入
    int length = write(1, "Here is some data\n", 18);
    if(length != 18) {
        write(2, "A write error has occurred on file descriptor 1 \n", 46);
    }
    return 0;
}
```

屏幕打印

```sh
Here is some data
```



### read


```c
#include<unistd.h>

size_t read(int fildes, void *buf, size_t nbytes)
```

从文件描述符fildes相关联的文件里读入nbytes个字节的数据, 并放到数据区buf中

| 情况                       | 返回值           |
| -------------------------- | ---------------- |
| 正常写入                   | 实际读入的字节数 |
| 未读入数据, 已经到达文件尾 | 0                |
| 调用错误                   | -1               |

```c
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void) {
    char buffer[128];
    int nread;
    int nwrite;
    // 从fd0中读入
    nread = read(0, buffer, 128);
    if(nread == -1) {
        write(2, "A read error has occurred\n", 26);
    }
    // 向fd1写入
    nwrite = write(1, buffer, nread);
    if(nwrite != nread) {
        write(2, "A write error has occurred\n", 27);
    }
    return 0;
}
```

键盘输入与屏幕输出

```sh
Hello World!
```



### open


```c
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int open(const char *path, int oflags);
int open(const char *path, int oflags, mode_t mode);
```

创建新的文件描述符, 调用成功后返回可以被read, write和其他系统调用那个使用的`文件描述符`

#### oflags参数

| 模式     | 说明         |
| -------- | ------------ |
| O_RDONLY | 只读方式打开 |
| O_WRONLY | 只写方式打开 |
| O_RDWR   | 读写方式打开 |


```c
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>

int main(void) {
    char block[1024];
    int in;
    int out;
    int nread;

    in = open("file.in", O_RDONLY);
    out = open("file.out", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
    while((nread = read(in, block, sizeof(block))) > 0) {
        write(out, block, nread);
    }
    return 0;
}
```
