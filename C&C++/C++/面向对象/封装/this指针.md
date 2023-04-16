<!--
 * @Description: 
 * @Version: 1.0
 * @Author: daLao
 * @Email: dalao@xxx.com
 * @Date: 2022-09-25 23:27:18
 * @LastEditors: dalao_li
 * @LastEditTime: 2023-04-16 23:10:27
-->


# this


## 概念

this 是 C++ 中的一个关键字, 是const 指针

### 指向

this 指针指向当前对象, 只能用在类的内部

this 可以访问类的所有private、protected、public 属性成员

### 赋值

对象被创建后编译器自动给 this 赋值, 用户不能显式赋值


```c++
#include <iostream>

class Person {
public:
    Person(std::string name);

    void printThis();

private:
    std::string name;
};

Person::Person(std::string name) {
    // this->name 表示是对象的成员变量name
    // 避免与参数name混淆
    this->name = name;
}

void Person::printThis() {
    // 输出this的值
    std::cout << "this = " << std::hex << this << std::endl;
}

int main(void) {
    Person p1{"Casper"};

    // this = 0x61fedc
    p1.printThis();

    // p address = 0x61fedc
    std::cout << "p address = " << std::hex << &p1 << std::endl;
}
```