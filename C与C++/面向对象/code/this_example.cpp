/*
 * @Description:
 * @Version: 1.0
 * @Author: daLao
 * @Email: dalao@xxx.com
 * @Date: 2022-09-26 00:05:09
 * @LastEditors: daLao
 * @LastEditTime: 2022-09-26 00:17:00
 */

#include <iostream>

class Person
{
public:
    Person(std::string name);

    void print_this();

private:
    std::string name;
};

Person::Person(std::string name)
{
    // this->name 表示是对象的成员变量name
    // 避免与参数name混淆
    this->name = name;
}

void Person::print_this()
{
    // 输出this的值
    std::cout << "this = " << std::hex << this << std::endl;
}

int main(void)
{
    Person p = Person("Casper");

    p.print_this();

    std::cout << "p address = " << std::hex << &p << std::endl;
}