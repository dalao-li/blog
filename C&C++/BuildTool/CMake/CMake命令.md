<!--
 * @Description指令
 * @Version: 1.0
 * @Author: dalao_li
 * @Email: dalao_li@163.com
 * @Date: 2023-09-16 16:02:42
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2023-12-14 21:57:19
-->

# CMake命令

```cpp
// Main.cpp
#include<iostream>

int main(void) {
    std::cout << "Hello World" << std::endl;\

    return 0;
}

// CMakeLists.txt
project(Hello)

set(SRC_LIST Main.cpp)

add_executable(hello ${SRC_LIST})
```

## 构建

- 使用当前目录CMakeList.txt, 当目录构建

```sh
cmake build
```

- 使用当前目录CMakeList.txt,  指定build目录构建

```sh
cmake -B build
```

此处使用MSVC编译器构建出了一个VS项目

![](https://cdn.hurra.ltd/img/20231202003303.png)


- 指定src目录的CMakeList.txt, 指定构建目录build

```sh
cmake -S src -B build
```

## 编译

- 当前目录编译

```sh
cmake --build .
```

- 在build目录下编译

```sh
cmake --build build
```

生成可执行文件hello
![](https://cdn.hurra.ltd/img/20231202004223.png)

## 安装

- 在build目录下安装

```sh
cmake --install build
```

## 卸载


[卸载 make install 编译安装的软件](https://blog.csdn.net/reasonyuanrobot/article/details/106732047)