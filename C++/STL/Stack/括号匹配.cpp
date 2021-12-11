/*
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-09-24 20:37:24
 * @LastEditors: DaLao
 * @LastEditTime: 2021-10-01 12:04:57
 */
#include<iostream>
#include<stack>
using namespace std;

int main(){
	stack<char> s;
	char str;
	int sum=0;
	cin>>str;
	s.push(str);
	while(cin>>str){
		if(str==s.top()){
			s.push(str);
		}
		else{
			s.pop();
			sum++;
		}
	}
	cout<<sum<<endl;
	return 0;
} 
