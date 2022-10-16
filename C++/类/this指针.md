<!--
 * @Description: 
 * @Version: 1.0
 * @Author: daLao
 * @Email: dalao@xxx.com
 * @Date: 2022-09-25 23:27:18
 * @LastEditors: daLao
 * @LastEditTime: 2022-10-11 18:19:43
-->


## this

this 是 C++ 中的一个关键字, 是一个 const 指针

this 指针指向当前对象, 只能用在类的内部, 通过 this 可以访问类的所有private、protected、public 属性成员

对象被创建以后才会给 this 赋值, 赋值过程编译器自动完成, 用户不能显式给 this 赋值


```c++
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
```
this指针指向当前对象, 对于不同的对象, this 的值也不一样

```c
this = 0x61fedc
p address = 0x61fedc
```


- this 是 const 指针,值不能被修改,一切企图修改该指针的操作都不允许的。

- this 只能在成员函数内部使用,用在其他地方没有意义

- 当对象被创建后 this 才有意义,因此不能在 static 成员函数中使用