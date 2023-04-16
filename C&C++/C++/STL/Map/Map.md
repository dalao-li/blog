<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2021-08-18 16:22:55
 * @LastEditors: dalao_li
 * @LastEditTime: 2023-04-16 23:25:17
-->

# Map


## 定义

```c++
template <class T, class V>
std::map<T, V> m;
```


## 添加


### 插入

```c
template <class T, class V>
map<T, V> m;

m.insert(make_pair(key, value))
```


### 添加

template <class T, class V>
std::map<T, V> m;

```c
m[key] = value
```


### 取值

```c
template <class T, class V>
std::map<T, V> m;

m[key]
```


### 遍历

```c++
template <class T, class V>
std::map<T, V> m;

// 方法1
for(map<T, V>::iterator it = m.begin(); it != m.end(); it++) {
    // it->first, it->second;
}

// 方法2
for (auto &[k, v] : m) {
    // k, v
}
```


### 查询

查找 key 是否存在, 若iterator 指向end() 即不存在

```c++
template <class T, class V>
std::map<T, V> m;

std::map<T, V>::iteraotr it;

it.find(key)
```


### 删除

删除键为 key 的键值对

```c++
template <class T, class V>
std::map<T, V> m;

m.erase(key)
```


## pair


### 初始化


```c++
pair<T, V> p;

p.first = key;
p.second = value;
```


```c++
pair<T, V> p;

p = make_pair(key, value);
```