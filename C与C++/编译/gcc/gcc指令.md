<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2022-05-21 23:09:51
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2023-03-09 01:34:10
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

编译指令

```c
gcc main.c -o main -DYES=1
```

运行结果

```c
OK
Hello World
```


#### -static

禁用动态库, 避免依赖问题, 但编译出程序较大

```c
gcc -static main.c -o main
```
