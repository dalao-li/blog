<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-02-13 19:00:24
 * @LastEditors: DaLao
 * @LastEditTime: 2022-03-27 23:29:38
-->

## 编写

建立一个 C Library 项目 hello

![](https://cdn.hurra.ltd/img/20201028180820.png)

library.c 文件中已有默认代码

![](https://cdn.hurra.ltd/img/20201028181141.png)

<kbd>ctrl</kbd> + <kbd>F9</kbd> 编译,右侧生成了 libhello.dll 文件
![](https://cdn.hurra.ltd/img/20201028181058.png)


## 调用

另建立一个项目 Demo，在其根目录下建立 lib 目录，将上一步生成的 dll 文件拷入
![](https://cdn.hurra.ltd/img/20201028182033.png)

main.cpp 内写入代码

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
编辑 Configurations，设置 Environment variables，值为 lib 目录的绝对路径

![](https://cdn.hurra.ltd/img/20201028184033.png)

运行
![](https://cdn.hurra.ltd/img/20201028184425.png)


## 测试

新建 C Library 项目 num

library.c 文件中写入

```c
#include "library.h"

#include <stdio.h>
#include <stdbool.h>

int add(int a， int b) {
    return a + b;
}

bool isLeapYear(int y) {
    return y % 400 == 0 || (y % 4 == 0 && y % 400 != 0);
}
```

编译，将 libnum.dll 文件拷入 Demo 项目的 lib 目录下

修改 Demo CMakeLists.txt 文件

```sh
# 新增
target_link_libraries(Demo libnum.dll)
```

修改 main.cpp 文件

```c
#include <iostream>

#ifdef __cplusplus

extern "C" {

#endif

void hello();

int add(int a， int b);

bool isLeapYear(int y);

#ifdef __cplusplus

}
#endif

int main() {
    hello();
    printf("%d\n"，add(3，4));
    
    int y1 = 2004;
    if(isLeapYear(y1)){
        printf("%d2004year is lead year\n"，y1);
    }
    return 0;
}
```

![](https://cdn.hurra.ltd/img/20201028194047.png)


