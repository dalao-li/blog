/*
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2022-02-13 19:00:24
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-20 21:40:26
 */

#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;

struct Lnode {
    int left;
    int right;
    int dep;
} Leaf[16];

queue<Lnode> q;

int depth = 1;

int wide = 1;

void dfs(int i , int deep) {
    Leaf[i].dep = deep;
    if(Leaf[i].left == 0 && Leaf[i].righ t== 0) {
        depth = depth > deep ? depth : deep;
    } else {
        if(Leaf[i].left != 0) {
            dfs(Leaf[i].left , deep + 1);
        } else if(Leaf[i].right != 0) {
            dfs(Leaf[i].right , deep + 1);
        }
    }
}


void bfs(int i) {
    q.push(Leaf[i]);
    int d = 0;
    int a = 1;
    while(!q.empty()) {
        Lnode L = q.front();
        q.pop();
        if(L.dep == a) {
            d++;
        } else {
            a = L.dep;
            wide = wide > d ? wide : d;
            d = 1;
        }
        if(L.left != 0) {
            q.push(Leaf[L.left]);
        }
        if(L.right != 0) {
            q.push(Leaf[L.right]);
        }
    }
}

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> Leaf[i].left >> Leaf[i].right;
    }
    dfs(1 , depth);
    for(int i = 1; i <= n; i++) {
        cout << Leaf[i].dep << endl;
    }
    bfs(1);
    cout << wide << " " << depth << endl;
    return 0;
}
