<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-08-18 16:22:55
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-10 00:24:00
-->
## 定义

```c
template <class T, class V>

map<T, V> m;

// 迭代器
map<T, V>::iterator it;
```

## 添加

```c
// 增加键值对
insert(make_pair(key, value))

m[key] = value
```

## 取值

```c
// 取得键为 key 的对应值
m[key]
```

## 查询

```c
// 查找 key 是否存在,若为 end()即不存在
iteraotr find(key)
```

## 删除

```c
// 删除键为 key 的键值对
erase(key)
```

## 遍历

```c++
for(map<T, V>::iterator it=m.begin(); it!=m.end(); it++) {
	key  = it->first;
	value = it->second;
}
```


