/*
 * @Description:
 * @Version: 1.0
 * @Author: dalao
 * @Email: dalao_li@163.com
 * @Date: 2022-04-18 16:55:09
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-18 17:24:52
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
        printf("%d ", v[i]);
    }
    return 0;
}