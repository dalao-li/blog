#include<iostream>
#include<fstream>
using namespace std;
int main() {
	int t;
	long long n;
	ofstream fout("a.txt");
	ifstream fin("a.txt");
	cin>>t;
	for(int i=0; i<t; i++) {
		cin>>n;
		fout<<n<<endl;
		fin>>n;
		cout<<n<<endl;
	}
	return 0;
}
