/*
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-12-27 16:50:01
 * @LastEditors: DaLao
 * @LastEditTime: 2021-12-27 16:50:02
 */
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
int main(){
    vector<int> v;
    int temp;
    for (int i = 0; i < 5; i++){
        scanf("%d", &temp);
        v.push_back(temp);
    }

    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
}