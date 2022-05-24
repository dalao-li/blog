<!--
 * @Description: 
 * @Version: 1.0
 * @Author: dalao
 * @Email: dalao_li@163.com
 * @Date: 2022-03-30 21:57:16
 * @LastEditors: DaLao
 * @LastEditTime: 2022-05-23 21:53:57
-->


## cin


```c
std::cin
```

```c
int n;

std::cin >> n;
```


### 回车结束输入


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