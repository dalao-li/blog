<!--
 * @Description: 
 * @Version: 1.0
 * @Author: dalao
 * @Email: dalao_li@163.com
 * @Date: 2022-03-30 21:57:16
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-18 20:00:12
-->


## cin


```c
std::cin
```



### 回车结束输入


```c
vector<T> v;
T value;

while (cin >> value){
    v.push_back(value);
    if (cin.get() == '\n')
        break;
    }
```