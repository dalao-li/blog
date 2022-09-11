/*
 * @Description:
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2022-02-13 19:00:24
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-16 13:38:47
 */

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    const int N = 5;
    int a[N][N];
    int i = 0;
    int j = 0;
    int k = 0;
    int m = 0;

    for (m = 0; m <= (N + 1) / 2; m++)
    {
        for (j = m; j < N - m; j++)
        {
            if (k == N * N)
            {
                break;
            }
            a[m][j] = ++k;
        }
        for (i = m + 1; i < N - m; i++)
        {
            if (k == N * N)
            {
                break;
            }
            a[i][N - 1 - m] = ++k;
        }
        for (j = N - 2 - m; j >= m; j--)
        {
            if (k == N * N)
            {
                break;
            }
            a[N - 1 - m][j] = ++k;
        }
        for (i = N - 2 - m; i > m; i--)
        {
            if (k == N * N)
            {
                break;
            }
            a[i][m] = ++k;
        }
    }
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%5d ", a[i][j]);
        }
        std::cout << endl;
    }
}
