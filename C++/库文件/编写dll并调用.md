<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-20 11:26:41
 * @LastEditors: DaLao
 * @LastEditTime: 2021-11-27 00:26:16
-->

## 编写

VS2019 选择创建动态链接库(DLL)项目

```c
// pch.h 文件
#ifndef PCH_H
#define PCH_H


#define DLLEXPORT extern "C" __declspec(dllexport)

// 添加要在此处预编译的标头
#include "framework.h"

DLLEXPORT int add(int a， int b);

DLLEXPORT void hello();

#endif //PCH_H
```

`#define DLLEXPORT extern "C" __declspec(dllexport)`

- windows 下需要使用\_\_declspec(dllexport)的声明来说明这个函数是动态库导出  

- extern "C"声明避免编译器对函数名称进行 name mangling，这对于使用 C++来编写 DLL/SO 是必须的

```c
// pch.cpp
#include "pch.h"
#include<iostream>

using namespace std;

int add(int a， int b) {
	return a + b;
}

void hello() {
	cout << "Hello World" << endl;
}
```

- 编译

![](https://cdn.hurra.ltd/img/20210120113257.png)

X86 将编译为 32 位的 dll

X64 将编译为 64 为的 dll

![](https://cdn.hurra.ltd/img/20210120113457.png)

## Python 调用

```py
from ctypes import *

pdll = CDLL("./Dll.dll")

print(pdll.add(1， 3))

pdll.hello()
```

![](https://cdn.hurra.ltd/img/20210120113618.png)

![](https://cdn.hurra.ltd/img/20210120113618.png)
