/*
 * @Description: 
 * @Version: 1.0
 * @Author: dalao
 * @Email: dalao_li@163.com
 * @Date: 2022-04-13 22:13:16
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-13 22:28:31
 */

#include<iostream>
#include<vector>
using namespace std;

// 用以进行哈夫曼编码
int code[20];
// 用以保存哈夫曼编码
string huffman[6];


template<class T>
typedef struct Tree {
    //节点的权值 
    T data;
    Tree *leftChild;
    Tree *rightChild;
    Tree(T data) {
        this->data = data;
        this->leftChild = NULL;
        this->rightChild = NULL:
    }
} Tree , *TreeList;

// 建哈夫曼树,返回根节点
template<class T>
TreeList createTree(vector<T> &v) {
    // 建立指针数组用来保存节点信息
    vector<TreeList> leaves;
    for (int i = 0; i < v.size(); i++) {
        leaves.push_back(Tree(v[i]))
    }
    // 建立一个节点作为哈夫曼树的根节点
    TreeList root = NULL;
    // 建立哈夫曼树 
    for (int i = 1; i < v.size(); i++) {
        // min1表示最小权值的树根结点的下标,min2为次小权值节点的下标
        int min1 = -1, min2;
        // 初始化min1与min2 
        for (int j = 0; j < v.size(); j++) {
            if (leaves[j] != NULL && min1 == -1) {
                min1 = j;
                continue;
            }
            if (leaves[j] != NULL) {
                min2 = j;
                break;
            }
        }
        // 找出最小值和次小值节点的下标
        for (int j = min2; j < LENGTH; j++) {
            if (leaves[j] != NULL) {
                if (leaves[j]->data < leaves[min1]->data) {
                    min2 = min1;
                    min1 = j;
                } else if (leaves[j]->data < leaves[min2]->data) {
                    min2 = j;
                }
            }
        }
        // 用最小权值树和次小权值树建立一棵新树,root指向树根结点
        root = new Tree;
        root->data = leaves[min1]->data + leaves[min2]->data;
        root->leftChild = leaves[min1];
        root->rightChild = leaves[min2];
        // 将指向新树的指针赋给leaves指针数组中min1位置
        leaves[min1] = root;
        // min2位置为空
        leaves[min2] = NULL;
    }
    return root;
}

// 根据权值获取下标
template<class T>
int getIndex(vecotr<T> v , int weight){
    for(int i = 0; i < v.size(); i++){
        if(v[i] == weight){
            return i;
        }
    }
    return -1;
} 

// 递归进行哈夫曼树编码,len是当前树的层数
template<class T>
void huffmanCoding(TreeList &root , int len , vector<T> &v) {
    if (root == NULL) {
        return;
    }
    // 若到叶子节点
    if (root->leftChild == NULL && root->rightChild == NULL) {
        // 获取该节点权值对应的字符下标 
        int index = getIndex(v , root->data);
        // 保存该字符的哈夫曼编码
        for (int i = 0; i < len; i++) {
            huffman[index].push_back(code[i] + '0');
        }
    }
    // 否则继续进行哈夫曼编码的操作
    else {
        // 左侧分支都记为零
        code[len] = 0;
        huffmanCoding(root->leftChild , len + 1 , v);
        // 右侧分支都记为一
        code[len] = 1;
        huffmanCoding(root->rightChild , len + 1 , v);
    }
}

int main(void) {
    vector<int> v = {12 , 24 , 35 , 67 , 46 , 55}; 

    vector<char> c = {'A' , 'B' , 'C' , 'D' , 'E' , 'F'};

    TreeList root = createTree(arr);
    huffmanCoding(root , 0 , v);
    for (int i = 0; i < v.size(); i++) {
        cout << c[i] << "的哈夫曼编码是 : " << huffman[i] << endl;
    }
    return 0;
}