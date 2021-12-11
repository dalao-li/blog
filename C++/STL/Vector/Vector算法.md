<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-11-15 21:05:31
 * @LastEditors: DaLao
 * @LastEditTime: 2021-11-27 00:22:10
-->

## 数值排序
  
```c
sort(v.begin(), v.end());
```

## 对象排序

```c
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
class Stu {
	private:
		string name;
		int num;
	public:
		Stu() {};
		string getName() {return name;}
		int getNum() {return num;}
        
		bool operator ==(const Stu &stu)const {
			return stu.name==name;
		}
};


bool cmp1(Stu a, Stu b) {
	return a.getName() < b.getName();
}

int main() {
    // 指定排序
    sort(stu.begin()，stu.end()，cmp1);
	
    // 寻找指定对象下标
    it = find(stu.begin()，stu.end()，s);
}
```

## 获取最值下标

```c
// 引用头文件
#include <functional>
#include <algorithm>
```

```c
// 迭代器指向最大值
vector<T>::iterator it = max_element(v.begin(),v.end());

vector<T>::iterator it = min_element(v.begin(),v.end());

// 下标
index = v.begin() - it;
```