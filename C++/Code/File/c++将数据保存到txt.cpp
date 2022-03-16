/*
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-10-06 13:11:32
 * @LastEditors: DaLao
 * @LastEditTime: 2022-03-15 22:04:58
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ofstream outfile;
	outfile.open("2.txt");
	if(!outfile) cout<<"error"<<endl;

	string str;
	int t1;
	int i=0;
	while(cin>>t1) {
		if(i!=0&&i%3==0)
			outfile<<"\n";
		outfile<<t1<<" ";
		i++;
	}

	outfile.close();
	return 0;
}
