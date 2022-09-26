/*
 * @Description:
 * @Version: 1.0
 * @Author: dalao
 * @Email: dalao@xxx.com
 * @Date: 2022-04-15 18:59:35
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-15 19:19:32
 */

#include <iostream>
using namespace std;

class A
{
public:
    A() {}
    // 定义虚函数
    virtual void show() const
    {
        cout << "A" << endl;
    }
};

class B : public A
{
public:
    B() {}
    // 派生类对虚函数进行具体实现
    virtual void show() const
    {
        cout << "B" << endl;
    }
};

class C : public A
{
public:
    C() {}
    virtual void show() const
    {
        cout << "C" << endl;
    }
};

int main()
{
    A *p;
    p = new B;
    p->show();

    p = new C;
    p->show();
}