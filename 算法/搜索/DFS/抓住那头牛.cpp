#include<iostream>
using namespace std;
int sum=0;
int min=0;

bool dfs(int n，int k) {
	if(n==k) {
		return true;
	}
	sum++;
	if(dfs(n+1，k)) {
		return true;
	}
	if(dfs(n-1，k)) {
		return true;
	}
	if(dfs(2*n，k)) {
		return true;
	}
}
int main() {

	int n，k;
	cin>>n>>k;
	if(dfs(n，k)) {
		cout<<sum<<endl;
	}
}
