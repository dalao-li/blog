/*
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-02-13 19:00:24
 * @LastEditors: DaLao
 * @LastEditTime: 2022-03-27 22:46:34
 */
#include<iostream>
#include<cstdio>
#include<windows.h>
#define N 5
using namespace std;

int main() {
	int a[N][N];
	int i , j , k=0 , m;
	for(m=0; m<=(N+1)/2; m++) {
		for(j=m; j<N-m; j++) {
			if(k==N*N) {
				break;
			}
			a[m][j]=++k;
		}
		for(i=m+1; i<N-m; i++) {
			if(k==N*N) {
				break;
			}
			a[i][N-1-m]=++k;
		}
		for(j=N-2-m; j>=m; j--) {
			if(k==N*N) {
				break;
			}
			a[N-1-m][j]=++k;
		}
		for(i=N-2-m; i>m; i--) {
			if(k==N*N) {
				break;
			}
			a[i][m]=++k;
		}
	}
	for(i=0; i<N; i++) {
		for(j=0; j<N; j++) {
			printf("%5d " , a[i][j]);
		}
		cout<<endl;
	}
}

