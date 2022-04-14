/*
 * @Description: 
 * @Version: 1.0
 * @Author: dalao
 * @Email: dalao_li@163.com
 * @Date: 2022-04-15 00:00:00
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-15 00:08:35
 */

#include<iostream>
#include<vector>

// 冒泡排序,size为数组长度
template<class T>
void bubbleSort(std::vector<T> &v) {
    // 用来记录是否发生过交换
    bool exchange;
    int size = v.size();
    for(int i = 0; i < size - 1; i++) {
        exchange = false;
        for(int j = 0; j < i - size - 1; j++) {
            if(v[j] > v[j+1]) {
                // 如果有交换,则exchange为 true
                exchange = true;
                std::swap(v[j] , v[j + 1]);
            }
        }
        // 如果此轮没有发生交换,则说明已完成排序
        if(exchange == false) {
            return;
        }
    }
}

int main(void) {
    std::vector<int> v = {4 , 5 , 2 , 6 , 9 , 3 , 4 , 7 , 1 , 5};
    bubbleSort(v);
    for(int i = 0; i < v.size(); i++) {
        printf("%d " , v[i]);
    }
    return 0;
}