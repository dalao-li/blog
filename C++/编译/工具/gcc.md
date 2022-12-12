<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2022-05-21 23:09:51
 * @LastEditors: daLao
 * @LastEditTime: 2022-10-02 22:19:53
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


### 优化

- -O1：它主要对代码的分支,常量以及表达式等进行优化

- -O2：尝试更多的寄存器级的优化以及指令级的优化,它会在编译期间占用更多的内存和编译时间

- -O3：在O2的基础上进行更多的优化,例如普通函数的内联,针对循环的更多优化

- -Os：主要是对代码大小的优化

