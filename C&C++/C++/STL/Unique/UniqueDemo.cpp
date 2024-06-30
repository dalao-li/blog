/*
 * @Description:
 * @Version: 1.0
 * @Author: DaLao
 * @Email:  
 * @Date: 2021-10-06 13:11:32
 * @LastEditors: DaLao
 * @LastEditTime: 2022-09-11 22:08:59
 */

#include <iostream>
#include <algorithm>

int main()
{
    int a[10] = {0, 7, 7, 6, 1, 1, 5, 5, 8, 9};
    int n = std::unique(a, a + 10) - a;

    // 7
    std::cout << n << std::endl;
    for (int i = 0; i < 10; i++)
    {
        // 0 7 6 1 5 8 9 5 8 9
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < n; i++)
    {
        // 0 7 6 1 5 8 9
        std::cout << a[i] << " ";
    }

    return 0;
}
