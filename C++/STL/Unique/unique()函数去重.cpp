/*
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-10-06 13:11:32
 * @LastEditors: DaLao
 * @LastEditTime: 2021-11-15 00:37:04
 */

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a[10] = { 0， 7， 7， 6， 1， 1， 5， 5， 8， 9 };
	int n = unique(a， a + 10) - a;
	cout << n << endl;  //n==7
	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";  //0 7 6 1 5 8 9 5 8 9
	for(int i=0; i<n; i++) {
		cout<<a[i]<<" ";      //0 7 6 1 5 8 9
	}
	return 0;
}
