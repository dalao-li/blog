/*
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-02-13 19:00:24
 * @LastEditors: DaLao
 * @LastEditTime: 2022-03-27 00:36:24
 */
#include<iostream>
using namespace std;
int sum=0;
int min=0;

bool dfs(int n,int k) {
	if(n==k) {
		return true;
	}
	sum++;
	if(dfs(n+1,k)) {
		return true;
	}
	if(dfs(n-1,k)) {
		return true;
	}
	if(dfs(2*n,k)) {
		return true;
	}
}
int main() {

	int n,k;
	cin>>n>>k;
	if(dfs(n,k)) {
		cout<<sum<<endl;
	}
}
