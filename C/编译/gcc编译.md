<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-05-21 23:09:51
 * @LastEditors: DaLao
 * @LastEditTime: 2022-09-03 00:14:31
-->

## GCC


### 命令


#### -o

直接编译出可执行文件

```c
gcc main.c -o main
```


#### -D

条件编译

```c++
#include <stdio.h>

int main(int argc, char *argv[]) {
    #if YES
        printf("OK\n");
    #endif
    
    printf("Hello World\n");

    return 0;
}
```

```c
gcc main.c -o main -DYES=1
```

```c
OK
Hello World
```


#### -static

禁用动态库, 避免依赖问题, 但编译出程序较大

```c
gcc -static main.c -o main
```