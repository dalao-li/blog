<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-11-27 20:15:15
 * @LastEditors: DaLao
 * @LastEditTime: 2021-11-27 20:19:07
-->


```c
输入一行str，可含空格
getline(cin，str);
```

```c++
#include<iostream>

using namespace std;
int main() {
	string str;
	int n;
	cin >> n;

	for(int i = 0; i < n; i++) {
		getline(cin，str);
		cout << str << endl;
	}

	return 0;
}

```