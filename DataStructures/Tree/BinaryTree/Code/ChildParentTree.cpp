/*
 * @Description:
 * @Version: 1.0
 * @Author: DaLao
 * @Email:  
 * @Date: 2022-02-13 19:00:24
 * @LastEditors: DaLao
 * @LastEditTime: 2022-07-19 21:57:23
 */
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#define MAX 5
using namespace std;

typedef struct Tree
{
    int data;
    int parent;
    int leftSon;
    int rightSon;
} Tree, *TreeList;

// 树的初始化
TreeList initTree(TreeList &root)
{
    root->leftSon = -1;
    root->rightSon = -1;
    return root;
}

//树的建立
//      12
//     / \
//    7   5
//   / \
//  1   4

// 建立出一个树
TreeList creatTree(TreeList &root)
{
    root = new Tree[MAX + 1];
    for (int i = 0; i < MAX; i++)
    {
        root[i].leftSon = -1;
        root[i].rightSon = -1;
    }

    for (int i = 0; i < MAX; i++)
    {
        cin >> root[i].data;
        cout << "节点值:" << root[i].data << endl;
        cin >> root[i].leftSon;
        cout << "左儿子编号:" << root[i].leftSon << endl;
        cin >> root[i].rightSon;
        cout << "右儿子编号:" << root[i].rightSon << endl;
    }

    for (int i = 0; i < MAX; i++)
    {
        cout << "节点值:" << root[i].data << endl;
        cout << "左儿子编号:" << root[i].leftSon << endl;
        cout << "右儿子编号:" << root[i].rightSon << endl;
    }
    return root;
}

// LDR        D B E A C
void inOrderTree(TreeList &root, int n)
{
    if (root[n].leftSon == -1 && root[n].rightSon == -1)
    {
        return;
    }
    inOrderTree(root, root[n].leftSon);
    cout << root[n].data << " ";
    inOrderTree(root, root[n].rightSon);
}

int main()
{
    TreeList root;
    root = creatTree(root);
    inOrderTree(root, 4);
}
