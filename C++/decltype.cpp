/*
 * @Description:
 * @Version: 1.0
 * @Author: dalao
 * @Email: dalao_li@163.com
 * @Date: 2022-04-19 19:05:47
 * @LastEditors: DaLao
 * @LastEditTime: 2022-09-11 22:10:35
 */

#include <iostream>

class Student
{
public:
    std::string name;
    int age;
    float scores;
};

int main(void)
{
    int n = 0;
    const int r = n;
    Student stu;

    // n 为 int 类型, a 被推导为 int 类型
    decltype(n) a = n;

    // r 为 const int 类型, b 被推导为 const int 类型
    decltype(r) b = n;

    // c为string类型
    decltype(stu.name) c = stu.name;

    return 0;
}