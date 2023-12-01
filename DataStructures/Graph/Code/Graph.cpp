#include <iostream>
#include <string>

#define MAX_NODE 20
#define MAX_WEIGHT 100

using namespace std;

typedef struct
{
    // 图中实际总顶点数
    int node_sum;
    // 图中实际总边数
    int edge_sum;
    // 顶点表
    char node[MAX_NODE];
    // 邻接矩阵
    int matrix[MAX_NODE][MAX_NODE];
    // 用来表示点某个点是否被选过
    bool is[MAX_NODE];
} Graph;

// 查找某个在顶点表中的位置, 不存在则返回-1
int get_node_position(Graph &g, char value)
{
    for (int i = 0; i < g.node_sum; i++)
    {
        if (g.node[i] == value)
        {
            return i;
        }
    }
    return -1;
}

// 查找某个顶点的第一个邻接顶点, 参数为顶点在顶点表中的位置
int get_first_node(Graph &g, int position)
{
    // 如果位置合法
    if (position != -1)
    {
        // 遍历顶点表
        for (int j = 0; j < g.node_sum; j++)
        {
            // 找到一个合法的邻接点
            if (g.matrix[position][j] > 0 && g.matrix[position][j] < MAX_WEIGHT)
            {
                // 返回该邻接点的位置
                return j;
            }
        }
    }
    return -1;
}

// 找出一个顶点除一个邻接顶点之外的另一个邻接顶点
int get_second_node(Graph &g, int position_a, int position_b)
{
    if (position_a != -1 && position_b != -1)
    {
        // 直接从 position_b + 1判断, 因为vertexPosition2之前的点肯定不是其邻接点
        for (int j = position_b + 1; j < g.node_sum; j++)
        {
            if (g.matrix[position_a][j] > 0 && g.matrix[position_a][j] < MAX_WEIGHT)
            {
                return j;
            }
        }
    }
    return -1;
}

// 初始化图函数, n, e代表顶点数和边数
void create_graph(Graph &g, int n, int e)
{
    g.node_sum = n;
    g.edge_sum = e;
    for (int i = 0; i < g.node_sum; i++)
    {
        // 标记该点为未选状态
        g.is[i] == false;
        char val;
        // 输入顶点值
        cin >> val;
        // 更新顶点表
        g.node[i] = val;
        for (int j = 0; j < g.node_sum; j++)
        {
            // 对角线值为0
            if (i == j)
            {
                g.matrix[i][j] = 0;
            }
            else
            {
                g.matrix[i][j] = MAX_WEIGHT;
            }
        }
    }
    // 初始化每一条边
    for (int i = 0; i < g.edge_sum; i++)
    {
        char e1, e2;
        int weight;
        // 输入这个边的两个点和权值
        cout << "输入这个边的两个点和权值" << endl;
        cin >> e1 >> e2 >> weight;
        // 获取这两个点在顶点表中的坐标
        int position1 = get_node_position(g, e1);
        int position2 = get_node_position(g, e2);
        // 更新邻接矩阵
        g.matrix[position1][position2] = weight;
        g.matrix[position2][position1] = weight;
    }
}

// 查找节点
char get_position(Graph &g, int position)
{
    if (position != -1)
    {
        return g.node[position];
    }
}

// 遍历图, 形参为最开始遍历的节点位置
void dfs(Graph &g, int position)
{
    cout << "->" << get_position(g, position);
    // 标记该位置为已选
    g.is[position] = true;
    //  firstNeighborVertex表示vertexPosition的第一个邻接点
    int neighborPosition = get_first_node(g, position);
    // 当vertexPosition的邻接点存在时
    while (neighborPosition != -1)
    {
        // 如果该点没有被选过
        if (g.is[neighborPosition] == false)
        {
            // 递归访问 下一个邻接点
            dfs(g, neighborPosition);
        }
        // 否则取 position 的另一个邻接点 neighborPosition
        neighborPosition = get_second_node(g, position, neighborPosition);
    }
}

// 求vertexPosition的最短路径
void get_shortest_path(Graph &g, int position, int distance[], int path[])
{
    // 最短路径顶点集合
    int path[MAX_NODE];
    for (int i = 0; i < g.node_sum; i++)
    {
        // 路径长度数组初始化, 其值为vertexPosition到其他每个点的距离
        distance[i] = g.matrix[position][i];
        // 表示顶点i是否求得最短路径
        path[i] = 0;
        // 如果从vertexPosition到i有边, path[i]为该边始顶点号vertexPosition
        if (i != position && distance[i] < MAX_WEIGHT)
        {
            path[i] = position;
        }
        // 若没有边则path[i]为-1
        else
        {
            path[i] = -1;
        }
    }
    // 顶点vertexPosition加入集合isGetShortestPath
    path[position] = 1;
    distance[position] = 0;
    // 逐个求得isGetShortestPath到其他顶点的最短路径
    for (int i = 0; i < g.node_sum - 1; i++)
    {
        int min = MAX_WEIGHT;
        // 选不在 isGetShortestPath中具有最短路径的顶点point
        int point = position;
        for (int j = 0; j < g.node_sum; j++)
        {
            // 如果该点j没有被选入且从vertexPosition到该点的距离小于min
            if (!path[j] && distance[j] < min)
            {
                // 更新位置
                point = j;
                // 更新最短路径
                min = distance[j];
            }
        }
        // 将顶点point加入isGetShortestPath集合
        path[point] = 1;
        // 修改经过point到其他顶点的路径长度
        for (int k = 0; k < g.node_sum; k++)
        {
            // weight为点point到点k的距离
            int weight = g.matrix[point][k];
            /* 如果点k未被选过
            且 点point到点k有边
            且 vertexPosition到点k的距离比vertexPosition经点point到点k的距离长*/
            if (!path[k] && weight < MAX_WEIGHT && distance[point] + weight < distance[k])
            {
                // vertexPosition到点k的距离路径可以缩短
                distance[k] = distance[point] + weight;
                //  vertexPosition到点k的前一个顶点为point
                path[k] = point;
            }
        }
    }
}

// 图的插入(插入一条边)
void insert_edge(Graph &g, int node_a, int node_b, int weight)
{
    if (node_a != -1 && node_b != -1)
    {
        // 邻接矩阵中添加该边
        g.matrix[node_a][node_b] = weight;
        g.matrix[node_b][node_a] = weight;
    }
}

// 图的插入(插入一个顶点)
void insert_node(Graph &g, char value)
{
    if (g.node_sum < MAX_NODE)
    {
        // 总节点数加1
        g.node_sum++;
        // 更新节点
        g.node[g.node_sum] = value;
    }
}

// 删除一条边
void del_edge(Graph &g, int node_a, int node_b)
{
    // 解除边的关系
    if (node_a != -1 && node_b != -1)
    {
        g.matrix[node_a][node_b] = MAX_WEIGHT;
        g.matrix[node_a][node_b] = MAX_WEIGHT;
    }
}

// 删除一个顶点和相应的边
void del_node(Graph &g, char value)
{
    // 找到该点的位置
    int position = get_node_position(g, value);
    // 将它换到顶点表的最后一位上去
    int temp = g.node[g.node_sum];
    g.node[g.node_sum] = g.node[position];
    g.node[position] = temp;
    // 转化边的关系
    for (int j = 0; j < g.node_sum; j++)
    {
        g.matrix[position][j] = MAX_WEIGHT;
        g.matrix[j][position] = MAX_WEIGHT;
    }
    g.matrix[position][position] = 0;
    // 总顶点数减1
    g.node_sum--;
}

int main()
{
    Graph g;
    create_graph(g, 4, 5);
    for (int i = 0; i < g.node_sum; i++)
    {
        for (int j = 0; j < g.node_sum; j++)
        {
            printf("%4d ", g.matrix[i][j]);
        }
        cout << endl;
    }
    cout << endl;
    dfs(g, 2);
    cout << endl;
    for (int i = 0; i < g.node_sum; i++)
    {
        g.is[i] == false;
    }
    int distance[MAX_NODE], path[MAX_NODE];
    get_shortest_path(g, 0, distance, path);
    for (int i = 0; i < g.node_sum; i++)
    {
        cout << distance[i] << endl;
    }
}
