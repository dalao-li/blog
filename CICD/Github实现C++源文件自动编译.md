<!--
 * @Description: 
 * @Version: 1.0
 * @Author: dalao_li
 * @Email: dalao_li@163.com
 * @Date: 2023-05-07 01:18:19
 * @LastEditors: dalao_li
 * @LastEditTime: 2023-05-07 01:22:39
-->

# Github实现C++源文件自动编译

## 目标

本地编写C++源文件, push到github仓库中后, github自动执行编译指令得到可执行文件并执行

## 本地设置

```c++
#include <iostream>

int main(void) {
    std::cout << "Hello World" << std::endl;

    return 0;
}
```

### yaml配置

根目录下新建.github/workflow目录, 建立build,yml文件


