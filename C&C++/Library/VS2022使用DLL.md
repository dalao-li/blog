<!--
 * @Description: 
 * @Version: 1.0
 * @Author: 
 * @Email: 
 * @Date: 2023-11-09 21:31:16
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2024-02-06 19:47:46
-->

# VS2022使用DLL


## DLL开发

建立项目DLLTest

![](https://cdn.hurra.ltd/img/20231109213828.png)

pch.h 与 pch.cpp分别写入

```c++
#include <iostream>

#define DLLEXPORT extern "C" __declspec(dllexport)

DLLEXPORT void helloworld();

DLLEXPORT int add(int x, int y);
```

```c++
void helloworld() {
    std::cout << "Hello World" << std::endl;
}


int add(int x, int y) {
    return x + y;
}
```

- windows 下需要使用\_\_declspec(dllexport)的声明来说明这个函数是动态库导出

- extern "C" 声明该函数按C语言方式进行编译

![](https://cdn.hurra.ltd/img/20231109220258.png)


![](https://cdn.hurra.ltd/img/20231109220434.png)

## DLL使用

新建项目,将生成的.dll与.lib文件拷贝到新项目目录下

建立头文件DLLTest.h

```c++
#include <iostream>

#define DLLEXPORT extern "C" __declspec(dllexport)

DLLEXPORT void helloworld();

DLLEXPORT int add(int x, int y);
```

### 添加DLL

![](https://cdn.hurra.ltd/img/20231109221318.png)

添加.lib的路径

![](https://cdn.hurra.ltd/img/20231109221410.png)


### 运行

cpp文件写入

```c++
#include "DLLTest.h"

int main()
{
    helloworld();

    std::cout << add(1, 2) << std::endl;
}
```

![](https://cdn.hurra.ltd/img/20231109221606.png)