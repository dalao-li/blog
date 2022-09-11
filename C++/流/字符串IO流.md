<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-09-02 21:24:26
 * @LastEditors: DaLao
 * @LastEditTime: 2022-09-11 21:54:53
-->


## sstream


### stringstream

读写string, 可用于数据类型转换


```c++
template <class T, class V>
void change_type(T &target, V &source)
{
    std::stringstream stream;

    stream << source;
    stream >> target;

    stream.str("");
    stream.clear();
}
```

- string 转 int32_t

```c++
#include <iostream>
#include <sstream>

...

int main()
{

    std::string source = "123456";

    int32_t target = 0;

    change_type(target, source);

    // 123456
    std::cout << target << std::endl;

    return 0;
}
```