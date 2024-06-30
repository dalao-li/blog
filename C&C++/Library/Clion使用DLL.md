<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email:  
 * @Date: 2021-01-20 11:26:41
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2023-11-09 22:21:39
-->

# Clion使用DLL

## 编写

建立一个 C Library 项目 hello

![](https://cdn.hurra.ltd/img/20201028180820.png)

library.c 文件中已有默认代码

![](https://cdn.hurra.ltd/img/20201028181141.png)

<kbd>ctrl</kbd> + <kbd>F9</kbd> 编译, 右侧生成了 libhello.dll 文件

![](https://cdn.hurra.ltd/img/20201028181058.png)

## 调用

另建立一个项目 Demo, 在其根目录下建立 lib 目录, 将上一步生成的 dll 文件拷入

![](https://cdn.hurra.ltd/img/20201028182033.png)

main.cpp 内写入

```c
#include <iostream>

#ifdef __cplusplus

extern "C" {

#endif

void hello();

#ifdef __cplusplus

}

#endif

int main() {
    hello();
    return 0;
}
```

CMakeList.txt 内容改为

```sh
cmake_minimum_required(VERSION 3.17)

# 项目名
project(Demo)

set(CMAKE_CXX_STANDARD 11)

# 新增;指项目根目录下的lib目录
link_directories(lib)

add_executable(Demo main.cpp)

# 新增;指目标链接的dll文件
target_link_libraries(Demo libhello.dll)
```

编辑 Configurations, 设置 Environment variables, 值为 lib 目录的绝对路径

![](https://cdn.hurra.ltd/img/20201028184033.png)

![](https://cdn.hurra.ltd/img/20201028184425.png)

## 测试

新建 C Library 项目 num

library.c 文件中写入

```c
#include"library.h"

#include<stdio.h>
#include<stdbool.h>

int add(int a, int b) {
    return a + b;
}

bool isLeapYear(unsigned int y) {
    return y % 400 == 0 || (y % 4 == 0 && y % 400 != 0);
}
```

编译, 将 libnum.dll 文件拷入 Demo 项目的 lib 目录下

修改 Demo CMakeLists.txt 文件

```sh
# 新增
target_link_libraries(Demo libnum.dll)
```

修改 main.cpp

```c++
#include <iostream>

#ifdef __cplusplus

extern "C" {

#endif

void hello();

int add(int a, int b);

bool isLeapYear(unsigned int y);

#ifdef __cplusplus

}
#endif

int main() {
    hello();
    printf("%d\n", add(3, 4));

    int y = 2004;

    if(isLeapYear(y)){
        printf("%d2004year is lead year\n", y);
    }

    return 0;
}
```

![](https://cdn.hurra.ltd/img/20201028194047.png)

## Python 调用

```py
from ctypes import *

pdll = CDLL("./Dll.dll")

print(pdll.add(1, 3))

pdll.hello()
```

![](https://cdn.hurra.ltd/img/20210120113618.png)

![](https://cdn.hurra.ltd/img/20210120113618.png)

## dll 与 lib的区别

- lib 是编译时调用, dll 是运行时调用

如果要完成源代码的编译, 只需要 lib

如果要使动态链接的程序运行起来, 只需要 dll

如果有 dll 文件, 那么 lib 一般是一些索引信息, 记录了 dll 中函数的入口和位置, dll 中是函数的具体内容

如果只有 lib 文件, 那么这个 lib 文件是静态编译出来的, 索引和实现都在其中.使用静态编译的 lib 文件, 在运行程序时不需要再挂动态库, 缺点是导致应用程序比较大, 而且失去了动态库的灵活性, 发布新版本时要发布新的应用程序才行

动态链接的情况下, 有两个文件, LIB 文件, DLL 文件

LIB 包含被 DLL 导出的函数名称和位置, DLL 包含实际的函数和数据, 应用程序使用 LIB 文件链接到 DLL 文件

在应用程序的可执行文件中, 存放的不是被调用的函数代码, 而是 DLL 中相应函数代码的地址, 从而节省了内存资源

DLL 和 LIB 文件必须随应用程序一起发行, 否则应用程序会产生错误

如果不想用 lib 文件或者没有 lib 文件, 可以用 WIN32 API 函数 LoadLibrary、GetProcAddress 装载
