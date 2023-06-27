/*
 * @Description:
 * @Version: 1.0
 * @Author: dalao_li
 * @Email: dalao_li@163.com
 * @Date: 2023-04-22 17:47:05
 * @LastEditors: dalao_li
 * @LastEditTime: 2023-06-13 21:19:56
 */
#include <iostream>
#include <thread>
#include <windows.h>
using namespace std;

void thread01()
{
    for (int i = 0; i < 5; i++)
    {
        cout << "Thread 01 is working! " << endl;
        Sleep(100);
    }
}

void thread02()
{
    for (int i = 0; i < 5; i++)
    {
        cout << "Thread 02 is working! " << endl;
        Sleep(200);
    }
}

int main()
{
    thread task01(thread01);
    thread task02(thread02);
    task01.detach();
    task02.detach();
    for (int i = 0; i < 5; i++)
    {
        cout << "Main thread is working! " << endl;
        Sleep(200);
    }

    // system("pause");
    return 0;
}
