/*
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-10-06 13:11:32
 * @LastEditors: DaLao
 * @LastEditTime: 2021-11-29 21:41:04
 */

#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main()
{
    vector<int> l1, l2;
    int b;
    while (cin >> b)
    {
        l1.push_back(b);
        if (cin.get() == '\n')
            break;
    }
    for (int i = 0; i < l1.size(); i++)
    {
        cout << l1[i];
    }
}