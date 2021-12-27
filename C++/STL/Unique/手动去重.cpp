/*
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-10-06 13:11:32
 * @LastEditors: DaLao
 * @LastEditTime: 2021-12-27 16:54:15
 */
 
#include <iostream>
#include <algorithm>

using namespace std;
const int len = 10;

int main() {
	int i = 0 , j = 0;
	
	int p[len] = { 0 , 7 , 7 , 6 , 1 , 1 , 5 , 5 , 8 , 9 };
	int t[len] = {0};  
	int counter = 1;  

	sort(p , p + len);   

	t[0] = p[0];

	while (i < len) {
		if (p[i] != p[++j]) {
			i = j;
			t[counter++] = p[i];  
		}
	}


	for (i = 0; i < (counter-1); i++)  
		cout << t[i] << " ";  //0 1 5 6 7 8 9

	return 0;
}
