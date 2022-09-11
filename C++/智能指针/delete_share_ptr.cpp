/*
 * @Description:
 * @Version: 1.0
 * @Author: dalao
 * @Email: dalao@xxx.com
 * @Date: 2022-04-19 18:50:48
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-19 18:53:31
 */

#include <iostream>
#include <memory>

class Sample
{
public:
    Sample()
    {
        std::cout << "构造函数调用" << std::endl;
    }
    ~Sample()
    {
        std::cout << "析构函数调用" << std::endl;
    }
};

void deleter(Sample *s)
{
    std::cout << "调用删除器" << std::endl;
    delete[] s;
}

int main()
{
    std::shared_ptr<Sample> p(new Sample[5], deleter);
    return 0;
}