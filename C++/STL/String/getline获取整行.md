<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-11-27 20:15:15
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-10 00:26:26
-->

## getline

输入一行str，可含空格

```c
getline(cin, str);
```

```c++
#include<iostream>

using namespace std;

const int n = 3;
int main() {
	string str;

	for(int i = 0; i < n; i++) {
		getline(cin,str);
		cout << str << endl;
	}

	return 0;
}

```