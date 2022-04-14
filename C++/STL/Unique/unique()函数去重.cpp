/*
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-10-06 13:11:32
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-15 00:15:34
 */

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a[10] = { 0 , 7 , 7 , 6 , 1 , 1 , 5 , 5 , 8 , 9 };
    int n = unique(a , a + 10) - a;
    cout << n << endl;  //n==7
    for (int i = 0; i < 10; i++){
        // 0 7 6 1 5 8 9 5 8 9
        cout << a[i] << " ";  
    }
    for(int i=0; i<n; i++) {
        // 0 7 6 1 5 8 9
        cout<<a[i]<<" ";      
    }
    return 0;
}
