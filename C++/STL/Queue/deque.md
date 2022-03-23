<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-07-16 22:43:26
 * @LastEditors: DaLao
 * @LastEditTime: 2022-03-23 21:10:04
-->

## deque

- 头文件

```c++
#include<deque>
```


### 插入

- 头部插入

```c
push_front()
```

- 尾部插入

```c
push_back()
```

- 插入元素 e 到 p 位置

```c
iterator insert(p , e)
```


### 删除

- 删除头部的元素

```c
pop_front()
```

- 删除尾部的元素

```c
pop_back()
```

- 删除 p 位置上元素

```c
iterator erase(iterator p)
```


### 查找

- 返回位置 p 上的元素

```c
reference at(size_type p)
```

- 返回头部元素

```c
front()
```

- 返回尾部元素

```c
back()
```


### 实例

```c
#include<iostream>
#include<deque>

using namespace std;

deque<int> q;

int main() {
	q = {1 , 2 , 3 , 4 , 5};

	// 1
	cout << q.front() << endl;

	// 5
	cout << q.back() << endl;

	// 4
	cout << q.at(3) << endl;

	// 4
	cout << q[3] << endl;

	// 插入在2位置666
	q.insert(q.begin()+2 , 666);

	// 删除1位置元素
	q.erase(q.begin() + 1);

	for(deque<int>::iterator it = q.begin(); it!=q.end(); it++){
		cout << *it << " ";
	}
}
```



