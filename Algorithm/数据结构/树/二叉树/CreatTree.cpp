/*
 * @Description:
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-10-06 13:11:32
 * @LastEditors: DaLao
 * @LastEditTime: 2022-07-03 01:38:35
 */

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

template <class T>
typedef struct Tree
{
    T data;
    Tree *leftSon;
    Tree *rightSon;
} Tree, *TreeList;

// 树的初始化
TreeList initTree(TreeList &root)
{
    root->leftSon = NULL;
    root->rightSon = NULL;
    return root;
}

//树的建立
//      A
//     / \
//    B   C
//   / \
//  D   E
// 建立出一个树  ABD##E##C##
TreeList creatTree(TreeList &root)
{
    char elem;
    scanf("%c", &elem);
    if (elem != '#')
    {
        root = new Tree;
        root->data = elem;
        root->leftSon = creatTree(root->leftSon);
        root->rightSon = creatTree(root->rightSon);
    }
    return root;
}

// LDR        D B E A C
void inOrderTree(TreeList &root)
{
    if (root == NULL)
    {
        return;
    }
    inOrderTree(root->leftSon);
    printf("%c ", root->data);
    inOrderTree(root->rightSon);
}

// 统计叶子节点个数
int sumLeaves(TreeList &root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->leftSon == NULL && root->rightSon == NULL)
    {
        return 1;
    }
    return sumLeaves(root->leftSon) + sumLeaves(root->rightSon);
}

// 统计节点的个数
int sumNode(TreeList &root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return sumNode(root->leftSon) + sumNode(root->rightSon) + 1;
    }
}

// 计算树的深度
int deepTree(TreeList &root)
{
    int left = deepTree(root->leftSon);
    int right = deepTree(root->rightSon);
    return (left > right ? left : right) + 1;
}

// 统计各个叶子到根节点的距离
void distanceRoot(TreeList &root, int sum)
{
    if (root->leftSon == NULL && root->rightSon == NULL)
    {
        std::cout << sum;
        return;
    }
    distanceRoot(root->leftSon, sum + 1);
    distanceRoot(root->rightSon, sum + 1);
}

int main()
{
    TreeList root;
    creatTree(root);
    inOrderTree(root);

    printf("\n树叶总个数为:%d\n", sumLeaves(root));
    distanceRoot(root, 0);
    printf("节点总个数为:%d\n树的深度为:%d\n", sumNode(root), deepTree(root));
    return 0;
}
