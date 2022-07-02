<!--
 * @Description: 
 * @Version: 1.0
 * @Author: dalao
 * @Email: dalao_li@163.com
 * @Date: 2022-02-13 19:00:24
 * @LastEditors: DaLao
 * @LastEditTime: 2022-05-10 22:42:10
-->


## 1 SPFA


![](https://cdn.hurra.ltd/img/2022-4-4-0152.svg)

求$A$到其他点的最短路



### 1.1 理论


建立一个队列,存入开始节点,队列不为空时,

$1)$ 取出队头节点 $X$,出队

$2)$ 遍历与 $X$ 相通的节点 $Y$,若 $X$ 到 $Y$ 的距离可缩小(松弛),且 $Y$ 不在队列中,将 $Y$ 入队,继续 $1)$

$3)$ 若队列为空则结束



### 1.2 过程


$1)$ 求 $A$ 节点到其余节点的最短路,设定 $p[i]$为 $A$ 到 $i$ 节点的路径

初始状态,建立点 $A$ 到其余各点的最短路径$∞$

|        | A   | B   | C   | D   | E   |
| ------ | --- | --- | --- | --- | --- |
| $p[i]$ | $0$ | $∞$ | $∞$ | $∞$ | $∞$ |


$2)$ 点 $A$ 进入队列,队列为$[A]$,队列非空时,

队头$A$ 出队,对以 $A$ 为起点的所有边松弛,涉及点 $B,E$

|        | A   | B    | C   | D   | E    |
| ------ | --- | ---- | --- | --- | ---- |
| $p[i]$ | $0$ | `13` | $∞$ | $∞$ | `70` |

![](https://cdn.hurra.ltd/img/2022-4-4-0156.svg)

点 $B,E$ 的最短路径变小,且其未在队列中,故点 $B,E$ 入队

队列为 $[B,E]$


$3)$ 队头 $B$ 出队,对以 $B$ 为起点的所有边进行松弛,涉及点 $C,D$

|        | A   | B    | C    | D    | E    |
| ------ | --- | ---- | ---- | ---- | ---- |
| $p[i]$ | $0$ | $13$ | `41` | `17` | $70$ |

![](https://cdn.hurra.ltd/img/2022-4-4-0158.svg)

到点 $C,D$ 的路径变小,且点其未在队列中,故点 $C,D$ 入队

队列为 $[E,C,D]$


$4)$ 队头 $E$ 出队,对以 $E$ 为起点的所有边的终点进行松弛操作


$5)$ 队头 $C$ 出队,对以 $C$ 为起点的所有边的终点进行松弛操作,涉及点$D,E$

|        | A   | B    | C    | D    | E    |
| ------ | --- | ---- | ---- | ---- | ---- |
| $p[i]$ | $0$ | $13$ | $41$ | $17$ | `56` |

![](https://cdn.hurra.ltd/img/2022-4-4-0159.svg)

到点 $E$ 的最短路径改变,且其未在队列中,点 $E$ 入队

队列中结点为 $[D,E]$


$6)$ 队头 $D$ 出队,对以 $D$ 为起点的边进行松弛

队列为$[E]$


$7)$ 队头 $E$ 出队,对以 $E$ 为起点的边进行松弛

队列为空,结束

点 $A$ 到其他点的最短路径为

|        | A   | B    | C    | D    | E    |
| ------ | --- | ---- | ---- | ---- | ---- |
| $p[i]$ | `0` | `13` | `41` | `17` | `56` |


```c++
const int SIZE = 5;
const int MAXV = 10000;

typedef struct Edge {
    char start_node;
    char end_node;
    int weight;
    Edge() {}
    Edge(char s , char e , int w) : start_node(s) , end_node(e) , weight(w) {}
} Edge;

vector<Edge> edge;

char node[5] = {'A' , 'B' , 'C' , 'D' , 'E'};

int path[SIZE];

int in[SIZE];

int getIndex(char n) {
    for(int i = 0; i < 5; i++) {
        if(node[i] == n) {
            return i;
        }
    }
    return -1;
}

// 求s到其他点间的最短路
void SPFA(char s) {
    char start_node;
    int start;
    char end_node;
    int end;
    queue<char> q;
    
    memset(path, MAXV, sizeof(path));
    memset(in, 0, sizeof(in));
    int index = getIndex(s);
    // 点s自己的最短路为0
    path[index] = 0;
    q.push(s);
    in[index] = 1;
    
    while (!q.empty()) {
        start_node = q.front();
        start = getIndex(start_node);
        q.pop();
        in[start] = 0;
        // 遍历所有与a所连通的节点, 进行松弛操作
        for (int i = 0; i < edge.size(); i++) {
            if(start_node != edge[i].start_node) {
                continue;
            }
            // 某个边的起点是a,获取该边的终点e
            end_node = edge[i].end_node;
            end = getIndex(end_node);
            // 若从点S经过点X到点end的距离比S直接到end的距离短, 则可进行松弛操作
            if (path[start] + edge[i].weight < path[end]) {
                // 从点S到点end的距离更新为点S到X的距离与X到end的距离之和
                path[end] = edge[i].weight + path[start];
                if (!in[end]) {
                    q.push(end_node);
                    in[end] = 1;
                }
            }
        }
    }
}
```