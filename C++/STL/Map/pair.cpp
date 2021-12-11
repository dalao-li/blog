/*
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-10-06 13:11:32
 * @LastEditors: DaLao
 * @LastEditTime: 2021-11-29 21:46:52
 */
#include<bits/stdc++.h>

using namespace std;
int main() {
	pair<int,double> p1;
	pair<int,double> p2;
	p1.first=1;
	p1.second=2.5;
	
	p2=make_pair(2,2.2);
	
	pair<int,double> p3=p1;
	
	cout<<"p1"<<" "<<p1.first<<" "<<p1.second<<endl;
	cout<<"p2"<<" "<<p2.first<<" "<<p2.second<<endl;
	cout<<"p3"<<" "<<p3.first<<" "<<p3.second<<endl;
}
