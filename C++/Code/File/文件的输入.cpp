/*
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-10-06 13:11:32
 * @LastEditors: DaLao
 * @LastEditTime: 2022-03-15 22:04:24
 */

#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	int n , *p;
	cin>>n;
	p=new int[n];
	ofstream outfile("file.txt" , ios::out);
	if(!outfile){
		cerr<<"open error!"<<endl;
		exit(1);
	}
	cout<<"enter "<<n<<" numbers:"<<endl;
	for(int i=0;i<n;i++){
		cin>>*(p+i);
		outfile<<*(p+i)<<" ";
	}
	outfile.close();
	delete[]p;
	return 0;
	
	
	
} 
