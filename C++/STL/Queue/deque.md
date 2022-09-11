<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-07-16 22:43:26
 * @LastEditors: DaLao
 * @LastEditTime: 2022-09-11 22:02:21
-->

## deque

头文件

```c++
#include<deque>
```


### 插入


#### 头部插入

```c
push_front()
```


#### 尾部插入

```c
push_back()
```


#### 插入元素 e 到 p 位置

```c
iterator insert(p, e)
```


### 删除


#### 删除头部的元素

```c
pop_front()
```


#### 删除尾部的元素

```c
pop_back()
```


#### 删除 p 位置上元素

```c
iterator erase(iterator p)
```


### 查找


#### 返回位置 p 上的元素

```c
reference at(size_type p)
```


#### 返回头部元素

```c
front()
```


#### 返回尾部元素

```c
back()
```


### 实例

```c++
#include<iostream>
#include<deque>

std::deque<int> d;

int main() {
    d = {1, 2, 3, 4, 5};

    // 1
    std::cout << d.front() <<  std::endl;

    // 5
    std::cout << d.back() << std::endl;

    // 4
    std::cout << d.at(3) << std::endl;

    // 4
    std::cout << d[3] << std::endl;

    // 插入在2位置666
    d.insert(d.begin()+2, 666);

    // 删除1位置元素
    d.erase(d.begin() + 1);

    for(std::deque<int>::iterator it = d.begin(); it!=d.end(); ++it){
        std::cout << *it << " ";
    }
}
```