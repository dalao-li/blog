/*
 * @Description:
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2021-10-06 13:11:32
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-08 21:07:08
 */

#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100

int n, W;

int w[MAX], v[MAX];

int rec(int i, int j)
{
    int res;
    if (i == n) {
        res = 0;
    }
    else if (j < w[i]) {
        res = rec(i + 1, j);
    }
    else {
        res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
    }
    return res;
}

int main() {
    cin >> W >> n;
    printf("%d\n", rec(0, W));
}
