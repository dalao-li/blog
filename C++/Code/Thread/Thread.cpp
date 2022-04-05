/*
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-10-06 13:11:32
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-05 23:25:49
 */
#include <iostream>
#include <thread>
#include <windows.h>

using namespace std;

void output1() {
	for (int i = 0; i < 4; i++) {
		//
	}
}

void output2() {
	for (int i = 0; i < 4; i++) {
		//
	}
}

int main() {

	thread t1(output1);
	thread t2(output2);

	t1.detach();
	Sleep(1000);
	t2.detach();
	Sleep(1000);
	return 0;
}
