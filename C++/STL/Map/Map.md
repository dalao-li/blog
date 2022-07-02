<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-08-18 16:22:55
 * @LastEditors: DaLao
 * @LastEditTime: 2022-05-06 20:55:55
-->

## 1 Map


### 1.1 定义

```c
template <class T , class V>
map<T , V> m;
```


### 1.2 添加

```c
template <class T , class V>
map<T , V> m;
```


#### 插入

```c
m.insert(make_pair(key , value))
```


#### 直接添加

```c
m[key] = value
```


### 1.3 取值

```c
template <class T , class V>
map<T , V> m;

m[key]
```


### 1.4 遍历

```c++
template <class T , class V>
map<T , V> m;

for(map<T , V>::iterator it = m.begin(); it != m.end(); it++) {
    // key = it->first;
    // value = it->second;
}
```


### 1.5 查询

查找 key 是否存在,若为 end()即不存在

```c
template <class T , class V>
map<T , V> m;

map<T , V>::iteraotr find(key)
```


### 删除

删除键为 key 的键值对

```c
template <class T , class V>
map<T , V> m;

m.erase(key)
```


## 2 pair


### 2.1 初始化


```c
pair<T , V> p;

p.first = key;
p.second = value;
```


```c
pair<T , V> p;

p = make_pair(key , value);
```