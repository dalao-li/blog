/*
 * @Description: 
 * @Version: 1.0
 * @Autor: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-16 17:59:35
 * @LastEditors: DaLao
 * @LastEditTime: 2021-01-26 10:45:21
 */

#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
//马走日
int dir[8][2] = {{-2， -1}， {-1， 2}， {2， 1}， {-1， -2}， {-2， 1}， {1， 2}， {2， -1}， {1， -2}};
//蹩了马脚
int vis[8][2] = {{-1， 0}， {0， 1}， {1， 0}， {0， -1}， {-1， 0}， {0， 1}， {1， 0}， {0， -1}};
int n = 5， m = 5;
int map[5][5];
//最小方案数
int MINV = 0x7fffffff;

int fun(int t)
{
	//每种方案之前要清0
	memset(map， 0， sizeof(map));
	//马的个数
	int cnt = 0;
	//马放的位置
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			//二进制该位为1
			if (t & 1)
			{
				//则该位有马
				map[i][j] = 1;
				cnt++;
			}
			else
			{
				map[i][j] = 0;
			}
			t >>= 1;
		}
	}
	//只要最少的马数量来满足条件
	if (cnt > MINV)
	{
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			//标记每个马可管辖的范围
			if (map[i][j] == 1)
			{
				for (int k = 0; k < 8; k++)
				{
					int x = i + dir[k][0];
					int y = j + dir[k][1];
					int tx = i + vis[k][0];
					int ty = j + vis[k][1];
					//超过范围或蹩马脚的位置有马
					if (x < 0 || y < 0 || x >= n || y >= n || map[tx][ty] == 1)
					{
						continue;
					}
					if (map[x][y] == 0)
					{
						//管辖该位置
						map[x][y] = 0x7fffffff;
					}
				}
			}
		}
	}
	//判断每个马是否管辖了整个棋盘
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!map[i][j])
			{
				return 0;
			}
		}
	}
	if (cnt < MINV)
	{
		MINV = cnt;
	}
	return cnt;
}
int main()
{
	int ans[26];
	memset(ans， 0， sizeof(ans));
	for (int i = 0; i < (1 << 25); i++)
	{
		int t = fun(i);
		//记录t个马满足条件的数量
		if (t)
		{
			ans[t]++;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (ans[i])
		{
			printf("%d\n%d\n"， i， ans[i]);
			return 0;
		}
	}
	return 0;
}
