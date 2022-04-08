<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-08-18 16:22:55
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-08 21:19:03
-->

## 1 Map


### 1.1 定义

```c
map<T , V> m;

map<T , V>::iterator it;
```


### 1.2 添加

```c
map<T , V> m;

m.insert(make_pair(key , value))

m[key] = value
```


### 1.3 取值

```c
map<T , V> m;

m[key]
```


### 1.4 遍历

```c++
map<T , V> m;

for(map<T , V>::iterator it = m.begin(); it != m.end(); it++) {
    // key = it->first;
    // value = it->second;
}
```


### 1.5 查询

查找 key 是否存在，若为 end()即不存在

```c
map<T , V> m;

map<T , V>::iteraotr find(key)
```


### 删除

删除键为 key 的键值对

```c
erase(key)
```


## 2 pair


### 2.1 初始化


```c
pair<T , V> p;

T key;

V value;

p.first = key;
p.second = value;
```


```c
pair<T , V> p;

T key;

V value;

p = make_pair(key , value);
```