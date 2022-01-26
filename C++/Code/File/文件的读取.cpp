#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;
int main() {
	string str;
	ifstream cinFile("Example.txt" , ios::in);
	ofstream coutFile("Example.txt" , ios::in);
	if(!cinFile) {
		cerr<<"open error!"<<endl;
		exit(1);
	}
	while(getline(cinFile , str)) {
		coutFile<<str;
		cout<<str<<endl;
	}
	cout<<endl;
	cinFile.close();
	return 0;
}
