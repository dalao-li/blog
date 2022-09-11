/*
 * @Description:
 * @Version: 1.0
 * @Author: dalao
 * @Email: dalao@xxx.com
 * @Date: 2022-04-08 20:34:38
 * @LastEditors: DaLao
 * @LastEditTime: 2022-07-19 21:59:44
 */

#include <iostream>
#include <vector>
#include <algorithm>

const int MAXZ = 10005;

const int n = 6;

// 边
typedef struct Edge
{
    // 起点
    int u;
    // 终点
    int v;
    // 权值
    int w;
    // 是否选择
    bool is;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
        this->is = false;
    }
} Edge;

int cmp(Edge &e1, Edge &e2)
{
    return e1.w <= e2.w;
}

class Graph
{
public:
    Graph()
    {
        for (int i = 0; i < n; i++)
        {
            p[i] = i;
        }
    }

    int find(int i)
    {
        int b = i;
        while (i != p[i])
        {
            i = p[i];
        }
        while (b != i)
        {
            p[b] = i;
            b = p[b];
        }
        return i;
    }

    void unions(int a, int b)
    {
        int x = find(a);
        int y = find(b);
        if (x != y)
        {
            p[x] = y;
        }
    }

    int kruskal()
    {
        sort(edges.begin(), edges.end(), cmp);
        // 记录最小生成树权值
        int sum = 0;
        int u;
        int v;
        for (int i = 0; i < edges.size(); i++)
        {
            u = edges[i].u;
            v = edges[i].v;
            if (find(u) != find(v))
            {
                sum += edges[i].w;
                unions(u, v);
                edges[i].is = true;
            }
        }
        return sum;
    }
    // 图中所有边
    std::vector<Edge> edges;
    int p[MAXZ];
};

int main(void)
{
    std::vector<Edge> v = {
        Edge(1, 6, 1), Edge(1, 5, 16), Edge(5, 6, 33), Edge(6, 2, 11), Edge(6, 4, 14),
        Edge(2, 4, 5), Edge(1, 2, 17), Edge(5, 4, 4), Edge(2, 3, 6), Edge(3, 4, 10)};

    Graph g;
    g.edges = v;
    std::cout << "最小生成树权值为:" << g.kruskal() << std::endl;
    for (int i = 0; i < g.edges.size(); i++)
    {
        if (g.edges[i].is)
        {
            printf("选取边:%d---%d,权值为:%d\n", g.edges[i].u, g.edges[i].v, g.edges[i].w);
        }
    }
    return 0;
}