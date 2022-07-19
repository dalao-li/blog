/*
 * @Description:
 * @Version: 1.0
 * @Author: dalao
 * @Email: dalao_li@163.com
 * @Date: 2022-04-08 22:47:18
 * @LastEditors: DaLao
 * @LastEditTime: 2022-07-19 21:56:30
 */

#include <iostream>
#include <vector>

using namespace std;

// 节点定义
template <class T>
struct BSTNode
{
    T value;
    BSTNode<T> *leftSon;
    BSTNode<T> *rightSon;
    BSTNode(T value, BSTNode<T> *leftSon, BSTNode<T> *rightSon)
    {
        this->value = value;
        this->leftSon = leftSon;
        this->rightSon = rightSon;
    }
};

// 查找
template <class T>
BSTNode<T> *searchBST(BSTNode<T> *&root, const T value)
{
    while (root)
    {
        if (root->value == value)
        {
            return root;
        }
        if (root->value > value)
        {
            root = root->leftSon;
        }
        if (root->value < value)
        {
            root = root->rightSon;
        }
    }
    return nullptr;
}

// 插入
template <class T>
BSTNode<T> *insertBST(BSTNode<T> *&root, const T value)
{
    // 当前节点为空,说明是叶子节点,可以插入
    if (root == nullptr)
    {
        root = new BSTNode<T>(value, nullptr, nullptr);
        return root;
    }
    // 值小于根结点时,插入根节点的左子树
    if (root->value > value)
    {
        root->leftSon = insertBST(root->leftSon, value);
    }
    // 值大于根结点时,插入根节点的右子树
    if (root->value < value)
    {
        root->rightSon = insertBST(root->rightSon, value);
    }
    return root;
}

// 构建
template <class T>
void createBST(BSTNode<T> *&root, vector<T> v)
{
    for (int i = 0, size = v.size(); i < size; i++)
    {
        root = insertBST(root, v[i]);
    }
}

// 遍历
template <class T>
void outputBST(BSTNode<T> *&root)
{
    if (root == nullptr)
    {
        return;
    }
    outputBST(root->leftSon);

    cout << root->value << " ";

    outputBST(root->rightSon);
}

// 删除
template <class T>
void deleteBST(BSTNode<T> *&root, T value)
{
    if (root == nullptr)
    {
        return;
    }
    // p为待删除节点,fp为其父节点
    BSTNode<T> *fp, *p = root;
    while (p->value != value)
    {
        fp = p;
        if (p->value > value)
        {
            p = p->leftSon;
        }
        if (p->value < value)
        {
            p = p->rightSon;
        }
    }
    // 情况1:p为叶子节点直接删
    if (p->leftSon == nullptr && p->rightSon == nullptr)
    {
        if (fp->leftSon != nullptr)
        {
            fp->leftSon = nullptr;
        }
        if (fp->rightSon != nullptr)
        {
            fp->rightSon = nullptr;
        }
        delete (p);
        return;
    }
    // 情况2:p左子树为空则重接右子树
    if (p->leftSon == nullptr)
    {
        p->value = p->rightSon->value;
        p->rightSon = nullptr;
        delete (p);
        return;
    }
    // 情况3:p右子树为空则重接左子树
    if (p->rightSon == nullptr)
    {
        p->value = p->leftSon->value;
        p->leftSon = nullptr;
        delete (p->leftSon);
        return;
    }
    // 情况4:p左右子树均不为空时,需要找p右子树中最小节点(最左节点)q
    BSTNode<T> *q = p->rightSon;
    // s为q的父节点
    BSTNode<T> *s = q;
    //循环查找左节点,就会找到最小值
    while (q->leftSon != nullptr)
    {
        s = q;
        q = q->leftSon;
    }
    s->leftSon = nullptr;
    //用最小值节点代替欲删除节点
    p->value = q->value;
    delete (q);
}

int main(int argv, char *argc[])
{
    vector<int> v = {11, 45, 9, 23, 76, 68};
    BSTNode<int> *root = nullptr;

    createBST(root, v);

    cout << "二叉排序树的中序遍历结果: ";
    outputBST(root);
    cout << endl;

    // 插入值
    int newNode = 35;
    cout << "插入新值:" << newNode << endl;
    root = insertBST(root, newNode);
    cout << "插入新值后二叉排序树的中序遍历结果: ";
    outputBST(root);
    cout << endl;

    // 删除值
    int delNode = 11;
    cout << "删除值:" << delNode << endl;
    deleteBST(root, delNode);
    cout << "删除值后二叉排序树的中序遍历结果: ";
    outputBST(root);
    cout << endl;
}