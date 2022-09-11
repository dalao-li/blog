/*
 * @Description:
 * @Version: 1.0
 * @Author: dalao
 * @Email: dalao_li@163.com
 * @Date: 2022-04-18 16:55:09
 * @LastEditors: DaLao
 * @LastEditTime: 2022-09-11 22:10:03
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    std::vector<int> v = {5, 2, 1, 4, 9};

    std::sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        std::cout << std::dec << v[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}