/*
 * @Description: 
 * @Version: 1.0
 * @Author: dalao
 * @Email: dalao_li@163.com
 * @Date: 2022-04-13 22:33:00
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-13 22:36:13
 */

#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

const int SIZE = 5;
const int MAXV = 10000;

using namespace std;

typedef struct Edge {
    char start_node;
    char end_node;
    int weight;
    Edge() {}
    Edge(char s, char e , int w) : start_node(s) , end_node(e) , weight(w) {}
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


int main() {
    Edge e[6];
    e[0] = Edge('A','B',13);
    e[1] = Edge('A','E',70);
    e[2] = Edge('B','D',4);
    e[3] = Edge('B','C',28);
    e[4] = Edge('C','D',23);
    e[5] = Edge('C','E',15);
    for(int i = 0; i < 6; i++) {
        edge.push_back(e[i]);
    }
    char s = 'A';
    SPFA(s);
    for(int i = 0 ; i<5;i++){
        cout << "p[" << node[i] << "] = " << path[i] << endl;
    }
    return 0;
}