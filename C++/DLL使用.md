<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-20 11:26:41
 * @LastEditors: DaLao
 * @LastEditTime: 2022-03-27 11:05:20
-->


## DLL


### 编写

VS2019 选择创建动态链接库(DLL)项目

```c
// pch.h 文件
#ifndef PCH_H
#define PCH_H


#define DLLEXPORT extern "C" __declspec(dllexport)

// 添加要在此处预编译的标头
#include "framework.h"

DLLEXPORT int add(int a, int b);

DLLEXPORT void hello();

#endif
```

`#define DLLEXPORT extern "C" __declspec(dllexport)`

- windows 下需要使用\_\_declspec(dllexport)的声明来说明这个函数是动态库导出  

- extern "C"声明避免编译器对函数名称进行 name mangling,这对于使用 C++来编写 DLL/SO 是必须的

```c
// pch.cpp
#include "pch.h"
#include<iostream>

using namespace std;

int add(int a , int b) {
	return a + b;
}

void hello() {
	cout << "Hello World" << endl;
}
```

### 编译

![](https://cdn.hurra.ltd/img/20210120113257.png)

X86 将编译为 32 位的 dll

X64 将编译为 64 为的 dll

![](https://cdn.hurra.ltd/img/20210120113457.png)


### Python 调用

```py
from ctypes import *

pdll = CDLL("./Dll.dll")

print(pdll.add(1,3))

pdll.hello()
```

![](https://cdn.hurra.ltd/img/20210120113618.png)

![](https://cdn.hurra.ltd/img/20210120113618.png)


### dll 与 lib的区别

- lib 是编译时调用，dll 是运行时调用

如果要完成源代码的编译，只需要 lib

如果要使动态链接的程序运行起来，只需要 dll

如果有 dll 文件，那么 lib 一般是一些索引信息，记录了 dll 中函数的入口和位置，dll 中是函数的具体内容

如果只有 lib 文件，那么这个 lib 文件是静态编译出来的，索引和实现都在其中.使用静态编译的 lib 文件，在运行程序时不需要再挂动态库，缺点是导致应用程序比较大，而且失去了动态库的灵活性，发布新版本时要发布新的应用程序才行

动态链接的情况下，有两个文件:一个是 LIB 文件，一个是 DLL 文件.

LIB 包含被 DLL 导出的函数名称和位置，DLL 包含实际的函数和数据，应用程序使用 LIB 文件链接到 DLL 文件.在应用程序的可执行文件中，存放的不是被调用的函数代码，而是 DLL 中相应函数代码的地址，从而节省了内存资源

DLL 和 LIB 文件必须随应用程序一起发行，否则应用程序会产生错误.如果不想用 lib 文件或者没有 lib 文件，可以用 WIN32 API 函数 LoadLibrary、GetProcAddress 装载
