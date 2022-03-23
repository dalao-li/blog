<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-08-18 16:22:55
 * @LastEditors: DaLao
 * @LastEditTime: 2022-03-23 21:10:35
-->

## Map

### 定义

```c
template <class T, class V>

map<T, V> m;

// 迭代器
map<T, V>::iterator it;
```

### 添加

```c
insert(make_pair(key, value))

m[key] = value
```

### 取值

```c
m[key]
```

### 查询

查找 key 是否存在，若为 end()即不存在

```c
iteraotr find(key)
```

### 删除

删除键为 key 的键值对

```c
erase(key)
```

### 遍历

```c++
for(map<T , V>::iterator it=m.begin(); it != m.end(); it++) {
	key = it->first;
	value = it->second;
}
```


