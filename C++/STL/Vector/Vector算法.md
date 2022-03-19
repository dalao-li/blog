<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-11-15 21:05:31
 * @LastEditors: DaLao
 * @LastEditTime: 2022-03-19 15:36:29
-->

## Vector算法


### 数值排序
  
```c
sort(v.begin() , v.end());
```

### 对象排序

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

		int getNum() {
			return num;
		}
        
		bool operator == (const Stu &stu) const {
			return stu.name == name;
		}
	private:
		string name;
		int num;
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

### 获取最值下标

引用头文件

```c
#include <functional>
#include <algorithm>
```

```c
// 迭代器指向最大值
vector<T>::iterator it = max_element(v.begin() , v.end());

vector<T>::iterator it = min_element(v.begin() , v.end());
```

- 下标
```
index = v.begin() - it;
```

### 累加

```c
accumulate(v.begin(), v.end(), 0, plus<T>())
```

### 累乘

```c
accumulate(v.begin(), v.end(), 1, multiplies<T>())
```