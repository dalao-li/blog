<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2022-05-21 23:09:51
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2023-03-09 13:13:41
-->

# gcc选项


### 编译

#### -E
仅进行预处理操作

```sh
gcc main.c -E -o main.i
```

#### -S
将预处理文件生成汇编文件
```sh
gcc main.i -S -o main.s
```


#### -c
将汇编文件生成目标文件
```sh
gcc main.s -c -o main.o
```


#### -o

直接生成可执行文件

```sh
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


```sh
# 编译指令
gcc main.c -o main -DYES=1

# 运行结果
OK
Hello World
```

#### -static

禁用动态库, 避免依赖问题, 但编译出程序较大

```c
gcc -static main.c -o main
```


#### -I

指定include头文件目录


### 提示

#### -w

忽略所有警告

#### -Werror

不区分警告和错误，遇到任何警告都停止编译

#### -Wall
对代码所有可能有问题的地方发出警告

#### -Wshadow
作用域相关存在变量同名时发出告警

#### -Wextra
对所有合法但值得怀疑的表达式发出告警