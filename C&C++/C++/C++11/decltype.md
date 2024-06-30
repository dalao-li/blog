<!--
 * @Description: 
 * @Version: 1.0
 * @Author: daLao
 * @Email:  
 * @Date: 2022-10-26 19:54:53
 * @LastEditors: daLao
 * @LastEditTime: 2023-04-19 11:59:27
-->

# decltype

decltype 指 declare type, 即声明类型, 是 C++11 新增的一个关键字, 功能是在编译时期进行自动类型推导

## 与auto区别

auto 和 decltype 关键字都可以自动推导出变量的类型

```c++
auto varName = value;

decltype(exp) varName = value;
```

varName 表示变量名, value 表示赋给变量的值, exp 表示一个表达式

auto 根据 = 右边的初始值 value 推导出变量的类型, 要求变量必须初始化

decltype 根据 exp 表达式推导出变量的类型, 跟 = 右边的 value 没有关系, 不要求变量必须初始化

## exp 注意事项

exp 就是一个普通的表达式, 它可以是任意复杂的形式, 但是必须要保证结果有类型, 不能是 void

当 exp 调用一个返回值类型为 void 的函数时, exp 的结果也是 void 类型, 此时就会导致编译错误


```c++
int a = 0;

// b 被推导成了 int
decltype(a) b = 1;

// x 被推导成了 double
decltype(10.8) x = 5.5;

// y 被推导成了 double
decltype(x + 100) y;
```

decltype 能够根据变量、字面量、带有运算符的表达式推导出变量的类型

## 推导规则

1. 如果 参数exp 是一个不被括号( )包围的表达式, 或者是一个类成员访问表达式, 或者是一个单独的变量, 则 decltype(exp) 的类型就和 exp 一致

2. 如果 exp 是函数调用, 则 decltype(exp) 的类型就和函数返回值的类型一致

3. 如果 exp 是一个左值, 或者被括号( )包围, 则 decltype(exp) 的类型就是 exp 的引用

假设 exp 的类型为 T, 那么 decltype(exp) 的类型就是 T&

- 一般情况

```c++
#include <iostream>
#include <string>

class Student
{
public:
    static int total;

    std::string name;

    int age;

    float scores;
};

int Student::total = 0;

int main()
{
    int n = 0;

    const int &r = n;

    Student stu;

    // n 为 int 类型, a 被推导为 int 类型
    decltype(n) a = n;

    // r 为 const int& 类型, b 被推导为 const int& 类型
    decltype(r) b = n;

    // total 为类 Student 的一个 int 类型的成员变量, c 被推导为 int 类型
    decltype(Student::total) c = 0;

    // total 为类 Student 的一个 string 类型的成员变量,  url 被推导为 string 类型
    decltype(stu.name) url = "http://666.com";

    return 0;
}
```

按照推导规则 1, 对于一般的表达式, decltype 的推导结果就和这个表达式的类型一致

- 函数调用

```c++
// 函数声明

// 返回值为 int&
int& func_int_r(int, char);

// 返回值为 int&&
int&& func_int_rr(void);

// 返回值为 int
int func_int(double);

// 返回值为 const int&
const int& fun_cint_r(int, int, int);

// 返回值为 const int&&
const int&& func_cint_rr(void);

// decltype类型推导
int n = 100;

// a 的类型为 int&
decltype(func_int_r(100, 'A')) a = n;

// b 的类型为 int&&
decltype(func_int_rr()) b = 0;

// c 的类型为 int
decltype(func_int(10.5)) c = 0;

// x 的类型为 const int &
decltype(fun_cint_r(1,2,3)) x = n;

// y 的类型为 const int&&
decltype(func_cint_rr()) y = 0;
```

参数exp 中调用函数时需要带上括号和参数, 但这仅仅是形式, 并不会真的去执行函数代码

- 参数exp 是左值, 或者被( )包围:

```c++
#include <iostream>

class Base
{
public:
    int x;
};

int main()
{
    const Base obj;
    //带有括号的表达式

    // obj.x 为类的成员访问表达式, 符合推导规则一, a 的类型为 int
    decltype(obj.x) a = 0;

    // obj.x 带有括号, 符合推导规则三, b 的类型为 int&
    decltype((obj.x)) b = a;

    // 加法表达式
    int n = 0, m = 0;

    // n+m 得到一个右值, 符合推导规则一, 所以推导结果为 int
    decltype(n + m) c = 0;

    // n=n+m 得到一个左值, 符号推导规则三, 所以推导结果为 int&
    decltype(n = n + m) d = c;

    return 0;
}

```

左值是指那些在表达式执行结束后依然存在的数据, 也就是持久性的数据

右值是指那些在表达式执行结束后不再存在的数据, 也就是临时性的数据

有一种很简单的方法来区分左值和右值, 对表达式取地址, 如果编译器不报错就为左值, 否则为右值

## 实际应用

auto 只能用于类的静态成员, 不能用于类的非静态成员(普通成员)

如果想推导非静态成员的类型, 就必须使用 decltype

```c++
#include <iostream>
#include <vector>


template <typename T>
class Base
{
public:
    void func(T& container)
    {
        m_it = container.begin();
    }
private:
    T::iterator m_it;  //注意这里
};

int main()
{
    const std::vector<int> v;

    Base<const std::vector<int>> obj;

    obj.func(v);

    return 0;
}
```

单独看 Base 类中 m_it 成员的定义, 很难看出会有什么错误, 但在使用 Base 类的时候, 如果传入一个 const 类型的容器, 编译器马上就会弹出一大堆错误信息

原因就在于, T::iterator并不能包括所有的迭代器类型, 当 T 是一个 const 容器时, 应当使用 const_iterator

有了 C++11 的 decltype, 可改为

```c++
template <typename T>
class Base 
{
public:
    void func(T& container)
    {
        m_it = container.begin();
    }
private:
    //  注意这里
    decltype(T().begin()) m_it;
};
```
