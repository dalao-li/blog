/*
 * @Description:
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2021-10-06 13:11:32
 * @LastEditors: DaLao
 * @LastEditTime: 2022-09-11 22:04:30
 */
#include <iostream>
#include <stack>

int main()
{
    std::stack<char> s;
    std::stack<double> e;

    std::string str;
    getline(std::cin, str);

    for (int i = str.size() - 1; i >= 0; i--)
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

    double first;
    double second;
    double mid;
    while (!s.empty() && e.size() != 1)
    {
        first = e.top();
        e.pop();

        second = e.top();
        e.pop();

        mid = s.top();
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

    std::cout << e.top() << std::endl;
}
