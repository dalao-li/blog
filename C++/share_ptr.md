<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-03-27 21:36:47
 * @LastEditors: DaLao
 * @LastEditTime: 2022-03-27 21:40:59
-->

## shared_ptr


### 初始化

- 构造出空智能指针

```c
std::shared_ptr<T> p;
```

- 构建 shared_ptr 智能指针，指向一块10 个 int 类型数据的堆内存空间

```c
std::shared_ptr<int> p(new int(10));
```

- std::make_shared<T>初始化

```c
std::shared_ptr<int> p = std::make_shared<int>(10);
```