/*
 * @Description:
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2022-09-11 22:53:27
 * @LastEditors: DaLao
 * @LastEditTime: 2022-09-11 23:06:16
 */

#include <iostream>
#include <thread>
#include <unistd.h>
#include <cstdlib>

void test_1() //普通的函数，用来执行线程
{
    for (int i = 0; i < 10; ++i)
    {
        std::cout << "test_1" << std::endl;
        sleep(1);
    }
}
void test_2()
{
    for (int i = 0; i < 20; ++i)
    {
        std::cout << "test_2" << std::endl;
        sleep(1);
    }
}
int main()
{
    std::thread th1(test_1); // 实例化一个线程对象th1，使用函数t1构造，然后该线程就开始执行了（t1()）
    std::thread th2(test_2);

    th1.join(); // 必须将线程join或者detach, 等待子线程结束主进程才可以退出
    th2.join();

    return 0;
}