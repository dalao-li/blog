<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-11-27 20:15:15
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-13 12:23:09
-->

## getline

输入一行可含空格的str

```c
getline(cin , str);
```

```c++
#include<iostream>
using namespace std;

int main() {
	string s;
	getline(cin , s);
	cout << s << endl;
	return 0;
}

```