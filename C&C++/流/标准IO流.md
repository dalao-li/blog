<!--
 * @Description: 
 * @Version: 1.0
 * @Author: dalao
 * @Email: dalao@xxx.com
 * @Date: 2022-03-30 21:57:16
 * @LastEditors: DaLao
 * @LastEditTime: 2022-09-11 21:52:47
-->

## iostream


### cin

输入流

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

输出流

```c
std::cout
```

### cerr

错误输出


cerr不经过缓冲而直接输出,一般用于迅速输出出错信息,是标准错误

### clog

日志输出