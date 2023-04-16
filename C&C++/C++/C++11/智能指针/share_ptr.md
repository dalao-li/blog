<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2022-03-27 21:36:47
 * @LastEditors: dalao_li
 * @LastEditTime: 2023-04-16 23:12:11
-->

# shared_ptr


## 初始化


### 构造出空智能指针

```c
std::shared_ptr<T> p;
```


### 赋值初始化

std::make_shared<T>初始化, 指向一块10 个 int 类型数据的堆内存空间

```c
std::shared_ptr<int> p = std::make_shared<int>(10);
```


## 引用


### 查看引用个数

```c
std::shared_ptr<int> p = std::make_shared<int>();

*p = 96;

// 1
p.use_count();
```