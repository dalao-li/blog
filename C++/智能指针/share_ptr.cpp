/*
 * @Description: 
 * @Version: 1.0
 * @Author: dalao
 * @Email: dalao_li@163.com
 * @Date: 2022-04-18 17:41:31
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-18 17:48:00
 */

#include<iostream>
#include<memory>

int main() {
    // 创建空对象
    std::shared_ptr<int> p = std::make_shared<int>();

    *p = 96;
    
    printf("p指向的值为:%d\np指针的引用个数为: %d\n" , *p , p.use_count());

    // 创建shared_ptr 对象指向同一个指针
    std::shared_ptr<int> p2(p);

    printf("p指针的引用个数为: %d\np2指针的引用个数为: %d\n" , p.use_count(), p2.use_count());

    // p指针指向空，则引用个数会自动归零
    p = NULL;
    printf("p指针的引用个数为: %d\n" , p.use_count());
}