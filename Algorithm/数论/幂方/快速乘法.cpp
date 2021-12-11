/*
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-10-06 13:11:32
 * @LastEditors: DaLao
 * @LastEditTime: 2021-12-01 20:01:57
 */

#include<iostream>
using namespace std;

typedef long long ll;

ll fastMul(int a,int b) {
	ll ans = 0;
	while(b) {
		if(b&1) {
			//将结果暂存在ans中 
			ans += a;
		} 
		b >>= 1; 
		a <<= 1;
	}
	return ans;
}
