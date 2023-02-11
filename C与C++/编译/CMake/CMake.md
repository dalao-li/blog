<!--
 * @Description: 
 * @Version: 1.0
 * @Author: daLao
 * @Email: dalao@xxx.com
 * @Date: 2022-10-16 23:03:11
 * @LastEditors: daLao
 * @LastEditTime: 2022-12-12 23:57:14
-->

## Cmake

[用CMake构建工程时 cmake -G "Unix Makefiles" 的使用](https://blog.csdn.net/yangjia_cheng/article/details/111408753)


### 单文件

Main.cpp

```c++
#include <iostream>

int main(void)
{
    std::cout << "Hello World" << std::endl;
    return 0;
}
```

- CMakeLists.txt

```sh
# CMake 最低版本号要求
cmake_minimum_required (VERSION 3.24.1)

# 编译器
set (CMAKE_C_COMPILER "C:/MinGW/bin/gcc.exe")
set (CMAKE_CXX_COMPILER "C:/MinGW/bin/g++.exe")

# 项目信息
project (CmakeDemo)

# 指定生成目标
add_executable(Main Main.cpp)
```


#### 生成Makefile

- Windows 环境

```c
cmake -G "Unix Makefiles" ..
```