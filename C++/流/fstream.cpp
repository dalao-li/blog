/*
 * @Description:
 * @Version: 1.0
 * @Author: dalao
 * @Email: dalao_li@163.com
 * @Date: 2022-04-19 22:00:11
 * @LastEditors: DaLao
 * @LastEditTime: 2022-07-15 23:09:46
 */

#include <iostream>
#include <fstream>
#include <cstdio>
#include <windows.h>
using namespace std;

int main()
{
    string str;

    ifstream in("Example.txt", ios::in);

    ofstream out("Example.txt", ios::in);

    if (!in)
    {
        cerr << "open error!" << endl;
        exit(1);
    }
    while (getline(in, str))
    {
        out << str;
        out << str << endl;
    }
    cout << endl;
    in.close();
    return 0;
}