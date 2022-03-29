<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-11-15 21:05:31
 * @LastEditors: dalao
 * @LastEditTime: 2022-03-29 22:40:02
-->

## Vector算法


### 排序

- 数字排序

```c
sort(v.begin() , v.end());
```

- 对象排序

```c++
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Stu {
	public:
		Stu() {};
		string getName() {
			return name;
		}
	private:
		string name;
};


bool cmp(Stu a, Stu b) {
	return a.getName() < b.getName();
}

int main() {
    // 指定排序
    sort(stu.begin() , stu.end() , cmp);

    // 寻找指定对象下标
    it = find(stu.begin() , stu.end() , s);
}
```


### 数学计算

- 最值

```c
#include <functional>
#include <algorithm>

...

// 迭代器指向最大值
vector<T>::iterator it = max_element(v.begin() , v.end());

vector<T>::iterator it = min_element(v.begin() , v.end());

// 下标
vector<T>::iterator index = v.begin() - it;
```

- 累加

```c
accumulate(v.begin() , v.end(), 0, plus<T>())
```

- 累乘

```c
accumulate(v.begin() , v.end(), 1, multiplies<T>())
```