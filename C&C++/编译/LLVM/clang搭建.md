<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2021-03-17 18:20:22
 * @LastEditors: daLao
 * @LastEditTime: 2023-04-17 15:56:27
-->

# clang搭建

## 安装

## 设置环境变量

- 查看版本

```sh
clang version 15.0.6
Target: x86_64-pc-windows-msvc
Thread model: posix
InstalledDir: C:\Program Files\LLVM\bin
```

## 使用

```sh
clang++ main.cpp -o main
```

### 错误

```sh
clang++: warning: unable to find a Visual Studio installation; try running Clang from a developer command prompt [-Wmsvc-not-found]
.\main.cpp:11:10: fatal error: 'iostream' file not found
#include <iostream>
         ^~~~~~~~~~
1 error generated.
```

Clang可以从GCC那借用C++标准库, 也就是libstdc++

在Windows上MinGW项目提供了一个Windows版的GCC, 包含libstd++可供Clang使用

### 设置target

```sh
clang++ -target x86_64-pc-windows-gnu .\main.cpp -o main
```

## 参考

[在Windows下配置Clang编译器](https://marvinsblog.net/post/2019-01-08-clang-on-windows/)