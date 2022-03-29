<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-11-15 20:40:55
 * @LastEditors: dalao
 * @LastEditTime: 2022-03-29 22:36:09
-->

## Vector

### 初始化

```c
vector<T> v;

vector<int> v = {1, 2 , 3 , 4 , 5};
```

- 二维Vector

```c
vector<vector<T> > v;
```


### 增加

- 尾部插入

```c
vector<T> v;

v.push_back(value);
```

- 在index位置插入value

```c
vector<T> v;

v.insert(v.begin() + index , value);
```

### 删除

- 删除x, y之间的元素

```c
vector<T> v;

v.earse(v.begin() + x , v.end() - y);
```

- 删除末尾元素

```c
vector<T> v;

v.pop_back();
```

- 删除index + 1位置元素

```c
vector<T> v;

v.erase(v.begin() + index)
```

- 清空

```c
v.clear();
```


### 遍历

```c
vector<T> v;

for(vector<T>::iterator it = v.begin(); it != v.end(); ++it) {
    // *it
}
```


### 翻转

```c
vector<T> v;

reverse(v.begin() , v.end());
```

