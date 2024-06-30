<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email:  
 * @Date: 2021-11-15 20:40:55
 * @LastEditors: dalao_li
 * @LastEditTime: 2023-04-16 23:27:46
-->

# Vector

## 初始化

### 赋值

```c++
std::vector<T> v;

std::vector<int> v = {1, 2, 3, 4, 5};
```

### 拷贝

```c++
std::vector<T> v(count, value);

// 初始化10个0
std::vector<int> v(10, 0);
```

### 预处理

若知道需保存数据量size, 可用reserve提前申请, 避免多次动态申请内存消耗时间

```c++
std::vector<T> v;

v.reserve(size);
```

### 二维Vector

```c
std::vector<vector<T> > v;
```

## 增加

### 尾部插入

```c++
std::vector<T> v;

v.push_back(value);
```

### 指定位置插入

```c++
std::vector<T> v;

// 在index位置插入value
v.insert(v.begin() + index, value);
```

## 遍历

### 迭代器访问

```c++
std::vector<T> v;

for(vector<T>::iterator it = v.begin(); it != v.end(); it++) {
    // *it
}

for(auto it = v.begin(); it != v.end(); it++) {
    // *it
}
```

### 下标访问

```c++
std::vector<T> v;

for(unsigned int i = 0; i < v.size(); i++){
    // v[i]
}
```

## 删除

### 删除x, y之间的元素

```c
std::vector<T> v;

v.earse(v.begin() + x, v.end() - y);
```

### 删除末尾元素

```c
std::vector<T> v;

v.pop_back();
```

### 删除index + 1位置元素

```c
std::vector<T> v;

v.erase(v.begin() + index)
```

### 清空

```c
std::vector<T> v;

v.clear();
```

## 翻转

```c
std::vector<T> v;

reverse(v.begin(), v.end());
```

## Vector算法

### 排序

#### 数字排序

```c
std::vector<T> v;

std::sort(v.begin(), v.end());
```

#### 对象排序

```c++
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Stu {
    public:
        string getName() {
            return name;
        }
    private:
        string name;
};

// 按姓名排序
bool cmp(Stu a, Stu b) {
    return a.getName() < b.getName();
}

std::vector<Stu> stu;

std::sort(stu.begin(), stu.end(), cmp);
```

### 数学计算

#### 最值

```c++
#include <functional>
#include <algorithm>

...

// 迭代器指向最大值
std::vector<T>::iterator it = max_element(v.begin(), v.end());

std::vector<T>::iterator it = min_element(v.begin(), v.end());

// 下标
std::vector<T>::iterator index = v.begin() - it;
```

#### 累加

```c++
accumulate(v.begin(), v.end(), 0, plus<T>())
```

#### 累乘

```c++
accumulate(v.begin(), v.end(), 1, multiplies<T>())
```
