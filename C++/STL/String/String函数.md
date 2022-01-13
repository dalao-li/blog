<!--
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-01-13 12:21:39
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-13 12:21:39
-->


## String STL函数

### find

```c++
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int sum=0;
	string s1, s2;
	cin >> s1 >> s2;
	for(int i = 0; i < s1.size(); i++){
		if(s1.find(s2, i) != string::npos){
			sum++;
		}
	}
	cout<<sum<<endl;
	return 0;
}
```

### erase

```c++
#include<iostream>
#include<string>
using namespace std;
int main(){
	string str = " 123 456237";
	int index = 3;
	int length = 1;
	for(int i = 0 ; i< str.size();i++){
		if()
	} 
	str.erase(index，length);
	cout<<str<<endl;
	return 0;
}
```