/*
 * @Description:
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-10-06 13:11:32
 * @LastEditors: DaLao
 * @LastEditTime: 2022-05-01 00:23:30
 */
#include <iostream>
#include <thread>
#include <ctime>

using namespace std;

void output1()
{
    printf("ouput1\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%d\n", i);
    }
}

void output2()
{
    printf("ouput2\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%d\n", i);
    }
}

int main()
{

    thread t1(output1);
    thread t2(output2);

    t1.detach();
    sleep(1000);
    t2.detach();
    sleep(1000);
    return 0;
}
