<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2022-05-21 23:09:51
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2023-12-03 00:38:33
-->

# gcc选项

## 编译

### -shared 动态库

```sh
gcc main.c -fPIC -shared -o main.so
```
- fPIC

创建与地址无关的编译程序 (pic, position independent code),为了能够在多个应用程序间共享

- shared

此选项将尽量使用动态库, 所以生成文件较小, 但需要系统动态库


### 单步

- -E

仅进行预处理操作

```sh
gcc main.c -E -o main.i
```

- -S

将预处理文件生成汇编文件

```sh
gcc main.i -S -o main.s
```

- -c

将汇编文件生成目标文件

```sh
gcc main.s -c -o main.o
```

- -o

直接生成可执行文件

```sh
gcc main.c -o main
```

### -I 添加头文件搜索路径

- 添加 /path/to/include 目录作为头文件搜索路径

```c
g++ -I /path/to/include source.cpp -o executable
```

### -L 添加库文件搜索路径

- 添加 /path/to/lib 目录作为库文件搜索路径

```sh
g++ -L /path/to/lib source.cpp -o executable
```

### -D 条件编译

```sh
# 仅编译YES宏包含部分
gcc main.c -o main -DYES=1
```

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
# 输出 
OK
Hello World
```

### -static 禁用动态库

避免依赖问题, 但编译出程序较大

```c
gcc -static main.c -o main
```

## 提示

### -w

忽略所有警告

### -Werror

不区分警告和错误, 遇到任何警告都停止编译

### -Wall

对代码所有可能有问题的地方发出警告

### -Wshadow

作用域相关存在变量同名时发出告警

### -Wextra

对所有合法但值得怀疑的表达式发出告警
