#include<iostream>
using namespace std;
int firstDay(int n) {
	int x1，x2=1;
	for(int i=n-1; i>=1; i--) {
		x1=2*(x2+1);
		x2=x1;
	}
	return x1;
}
int main() {
	int n;
	while(cin>>n) {
		cout<<firstDay(n)<<endl;
	}
	return 0;
}
