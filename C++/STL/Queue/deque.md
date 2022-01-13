<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-07-16 22:43:26
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-13 12:19:24
-->

## deque

- 头文件

```c++
#include<deque>
```


### 插入

- `push_front` 头部插入 

- `push_back()` 尾部插入 

- `iterator insert(p , e)` 插入元素 e 到 p 位置 


### 删除

- `pop_front()` 删除头部的元素 
  
- `pop_back()` 删除尾部的元素 

- `iterator erase(iterator p)` 删除 p 位置上元素 


### 查找

- `reference at(size_type p)` 返回位置 p 上的元素 
  
- `front()` 返回头部元素

- `back()`返回尾部元素 


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



