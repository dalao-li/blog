<!--
 * @Description: 
 * @Version: 1.0
 * @Author: dalao
 * @Email: dalao_li@163.com
 * @Date: 2022-03-30 21:57:16
 * @LastEditors: DaLao
 * @LastEditTime: 2022-09-02 21:20:43
-->

## iostream


### cin


```c
std::cin
```

- 回车结束输入


```c
vector<T> v;

T value;

while (std::cin >> value) {
    v.push_back(value);
    if (std::cin.get() == '\n')
        break;
    }
}
```


### cout


### cerr


### clog