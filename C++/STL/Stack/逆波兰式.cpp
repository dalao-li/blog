/*
 * @Description:
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-10-06 13:11:32
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-01 21:39:34
 */
#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<char> s;
    stack<double> e;
    string str;
    getline(cin, str) for (int i = str.size() - 1; i >= 0; i--)
    {
        if (str[i] > '0' && str[i] <= '9')
        {
            e.push(str[i] - '0');
        }
        else
        {
            s.push(str[i]);
        }
    }
    while (!s.empty() && e.size() != 1)
    {
        double first = e.top();
        e.pop();
        double second = e.top();
        e.pop();
        char mid = s.top();
        s.pop();
        if (mid == '+')
        {
            e.push(first + second);
        }
        else if (mid = '-')
        {
            e.push(first + second);
        }
        else if (mid = '*')
        {
            e.push(first * second);
        }
        else if (mid = '/')
        {
            e.push(first / second);
        }
    }
    cout << e.top() << endl;
}
