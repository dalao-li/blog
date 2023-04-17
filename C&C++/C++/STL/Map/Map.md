<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2021-08-18 16:22:55
 * @LastEditors: daLao
 * @LastEditTime: 2023-04-17 16:26:12
-->

# Map

## 定义

```c++
template <class T, class V>
std::map<T, V> m;
```

## 插入

```c++
m.insert(make_pair(key, value))
```

## 添加

```c++
m[key] = value
```

## 取值

```c++
m[key]
```

## 遍历

```c++
// 方法1
for(map<T, V>::iterator it = m.begin(); it != m.end(); it++) {
    // it->first, it->second;
}

// 方法2
for (auto &[k, v] : m) {
    // k, v
}
```

## 查询

查找 key 是否存在, 若iterator 指向end() 即不存在

```c++
std::map<T, V>::iteraotr it;

it.find(key)
```

## 删除

删除键为 key 的键值对

```c++
template <class T, class V>
std::map<T, V> m;

m.erase(key)
```
