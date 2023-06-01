/*
 * @Description:
 * @Version: 1.0
 * @Author: dalao
 * @Email: dalao@xxx.com
 * @Date: 2022-04-18 17:41:31
 * @LastEditors: dalao_li
 * @LastEditTime: 2023-06-01 23:20:41
 */

#include <iostream>
#include <memory>

int main()
{
    int value = 0x3FF;

    // 创建空对象
    std::shared_ptr<int> p = std::make_shared<int>(value);

    std::cout << "p指向的值为:" << std::hex << *p << std::endl;
    std::cout << "p指针的引用个数为:" << p.use_count() << std::endl;

    // 创建shared_ptr 对象指向同一个指针
    std::shared_ptr<int> p2(p);

    std::cout << std::hex << &value << std::endl;

    std::cout << "p指向的值为:" << *p << std::endl;
    std::cout << "p指针的引用个数为:" << p.use_count() << std::endl;

    std::cout << std::hex << p.get() << std::endl;

    // p指针指向空, 则引用个数会自动归零
    p = nullptr;
    std::cout << "p指针的引用个数为:" << p.use_count() << std::endl;
}