/*
 * @Description: 
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-16 17:59:38
 * @LastEditors: DaLao
 * @LastEditTime: 2021-02-20 20:49:07
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <thread>

int main() {
    int num_threads;
    std::thread t[num_threads];
    std::cin>>num_threads;
    //Launch a group of threads 启动一组线程
    for (int i = 0; i < num_threads; ++i) {
        t[i] = std::thread(call_from_thread);
    }
    std::cout << "Launched from the mainn";
    //Join the threads with the main thread
    for (int i = 0; i < num_threads; ++i) {
        t[i].join();
    }
    return 0;
}

