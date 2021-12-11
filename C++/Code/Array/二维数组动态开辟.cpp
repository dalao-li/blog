/*
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-10-06 13:11:32
 * @LastEditors: DaLao
 * @LastEditTime: 2021-11-27 20:37:44
 */
#include<iostream>
using namespace std;

const int n = 10;
const int m = 10;
int main()
{
	cin >> n >> m;
	int **a = new int *[m];
	for(int i = 0; i < n; i++){
		a[i] = new int[n];
	}
	for(int i = 0;i < n;i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
 
    for(int i = 0; i < n; i++){  
        delete a[i];  
    }  
    delete []a;  

    return 0;
}
