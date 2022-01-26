/*
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-10-06 13:11:32
 * @LastEditors: DaLao
 * @LastEditTime: 2022-01-26 22:51:27
 */
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef struct {
	int top[2];
	int bot[2];
	int *V;
	int m;
} DouStack;

void initialize(DouStack &S) {
	S.m =MAXSIZE;
	S.V = (int *)malloc(MAXSIZE * sizeof(DouStack));
	S.bot[0]=S.top[0]=-1;
	S.bot[1]=S.top[1]=S.m;
}

bool isStackEmpty(DouStack &S , int num) {
	if(num==0&&S.top[num]==-1) {
		return true;
	} else if(num==1&&S.top[num]==S.m) {
		return true;
	}
	return false;
}

bool isStackFull(DouStack &S) {
	if(S.top[1]-S.top[0]==1&&(S.top[0]!=-1||S.top[1]!=S.m)) {
		return true;
	}
	return false;
}

void push(DouStack &S , int num , int &e) {
	if(isStackEmpty(S , num)) {
		return ;
	}
	int index = S.top[num];
	if(num==0) {
		index++;
	} else {
		index--;
	}
	S.V[index]=e;
}

int pop(DouStack &S , int num) {
	if(isStackEmpty(S , num)) {
		return -1;
	}
	int index = S.top[num];
	int e;
	e=S.V[index];
	S.V[index]=-1;
	if(num==0) {
		S.top[index]--;
	} else {
		S.top[index]++;
	}
	return e;
}
int main() {

}
