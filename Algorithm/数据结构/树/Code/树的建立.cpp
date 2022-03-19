/*
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-10-06 13:11:32
 * @LastEditors: DaLao
 * @LastEditTime: 2022-03-18 23:42:15
 */

#include<stdio.h>
#include<iostream>
#include<stdlib.h>

typedef struct Tree {
	char data;
	Tree *leftSon;
	Tree *rightSon;
} Tree,*TreeList;

// 树的初始化
TreeList initTree(TreeList root) {
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
TreeList creatTree(TreeList &root) {

	char elem;
	scanf("%c",&elem);
	if(elem!='#') {
		root = (TreeList)malloc(sizeof(Tree));
		root->data = elem;
		root->leftSon = creatTree(root->leftSon);
		root->rightSon = creatTree(root->rightSon);
	}
	return root;
}

// LDR        D B E A C
void inOrderTree(TreeList &root) {
	if(root!=NULL) {

		inOrderTree(root->leftSon);
		printf("%c ",root->data);
		inOrderTree(root->rightSon);
	}
}

// 统计叶子节点个数
int sumOfLeaves(TreeList &root) {
	if(root==NULL) {
		return 0;
	} else if(root->leftSon==NULL&&root->rightSon==NULL) {
		return 1;
	} else {
		return sumOfLeaves(root->leftSon)+sumOfLeaves(root->rightSon);
	}
}

// 统计节点的个数
int sumOfNode(TreeList &root) {
	if(root==NULL) {
		return 0;
	} else {
		return sumOfNode(root->leftSon)+sumOfNode(root->rightSon)+1;
	}
}

// 计算树的深度
int deepOfTree(TreeList &root) {
	return max(deepOfTree(root->leftSon),deepOfTree(root->rightSon))+1;
}


// 统计各个叶子到根节点的距离
void  distanceFromRoot(TreeList &root,int sum) {
	if(root->leftSon==NULL&&root->rightSon==NULL) {
		std::cout<<sum;
		sum=0;
	} else {
		distanceFromRoot(root->leftSon,sum+1);
		distanceFromRoot(root->rightSon,sum+1);
	}
}


int main() {
	TreeList root;

	creatTree(root);
	inOrderTree(root);
	printf("\n");
	printf("树叶总个数为:%d\n",sumOfLeaves(root));
	distanceFromRoot(root,0);
	printf("节点总个数为:%d\n",sumOfNode(root));
	printf("树的深度为:%d\n",deepOfTree(root));
	return 0;
}
