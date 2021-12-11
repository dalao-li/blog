<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-07-16 22:43:26
 * @LastEditors: DaLao
 * @LastEditTime: 2021-09-15 23:39:04
-->
## 头文件

```c++
#include<deque>
```


## 插入

- 头部插入 `push_front`

- 尾部插入 `push_back()`

- 插入元素 elem 到 pos 位置 `iterator insert(pos，elem)`

## 删除

- 删除头部的元素 `pop_front()`
  
- 删除尾部的元素 `pop_back()`

- 删除 pos 位置上元素 `iterator erase( iterator pos )`

## 查找

- 返回位置 pos 上的元素 `reference at( size_type pos )`
  
- 返回头部元素 `front()`

- 返回尾部元素 `back()`

## 实例

```c
#include<iostream>
#include<deque>
using namespace std;

//定义一个双向队列
deque<int> q;

deque<int>::iterator it;

int main() {
	q = {1，2，3，4，5};

	cout<<q.front()<<endl;

	cout<<q.back()<<endl;

	cout<<q.at(3)<<endl;

	cout<<q[3]<<endl;

	q.insert(q.begin()+2，666);

	for(int i = 0 ，size = q.size(); i<size;i++){
		cout<<q[i]<<" ";
	}
	cout<<endl;

	q.erase(q.begin()+1);

	for(it = q.begin();it!=q.end();it++){
		cout<<*it<<" ";
	}
}
```

![](https://cdn.hurra.ltd/img/20200905113424.png)

---


