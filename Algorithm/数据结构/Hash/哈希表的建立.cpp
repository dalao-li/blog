/*
 * @Description: 
 * @Version: 1.0
 * @Author: dalao
 * @Email: dalao_li@163.com
 * @Date: 2022-04-04 22:12:44
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-04 23:41:10
 */

#include<iostream>
#include<malloc.h>

// 哈希表表长
const int  TABLE_LENGTH = 50

// 人名最大个数
const int NAME_MAX_NUM = 30

// 除数
const int M = 47

using namespace std;

typedef struct {
    // 用户的名字
    string name;
    // 该名字所对应的关键字
    int keyword;
} NameList;
 

typedef struct {
    NameList unit;
    // 查找次数
    int count;
} HashTable;

void initNameList(NameList unit[]) {
    unit[0].name = "Addison";
    unit[1].name = "Albert";
    unit[2].name = "Alfred";
    unit[3].name = "Barton";
    unit[4].name = "August";
    unit[5].name = "Charles";
    unit[6].name = "Paul";
    unit[7].name = "Georg";
    unit[8].name = "Michael";
    unit[9].name = "Elizabeth";
    unit[10].name = "Kate";
    unit[11].name = "Sarah";
    unit[12].name = "Tiffany";
    unit[13].name = "Nancy";
    unit[14].name = "Thomas";
    unit[15].name = "Jack";
    unit[16].name = "Clark";
    unit[17].name = "Johnson";
    unit[18].name = "Tayler";
    unit[19].name = "Hugo";
    unit[20].name = "Gino";
    unit[21].name = "Gavin";
    unit[22].name = "Garfield";
    unit[23].name = "Frank";
    unit[24].name = "Bob";
    unit[25].name = "Anthony";
    unit[26].name = "Alva";
    unit[27].name = "Jesse";
    unit[28].name = "Isaac";
    unit[29].name = "Harrison";
    for(int i = 0; i < NAME_MAX_NUM; i++) {
        // sum代表该人名字各字符的ASCLL码值之和
        int sum = 0;
        for(int j = 0; j < unit[i].name.size(); j++) {
            sum += unit[i].name[j];
        }
        // 更新关键字
        unit[i].keyword = sum;
    }
}

// 建立哈希表 , m为散列函数中的被除数
void creatHashTable(HashTable hashUnit[], NameList unit[]) {
    // 哈希表初始化
    for(int i = 0 ; i < TABLE_LENGTH ; i++) {
        hashUnit[i].unit.name = "";
        hashUnit[i].unit.keyword = 0;
        hashUnit[i].count = 0;
    }

    // 构建哈希表,遍历每一个姓名单元,将它们插入到哈希表上去
    for(int i = 0; i < NAME_MAX_NUM; i++) {
        // startAddress代表该姓名单元最初储存地址,其值为姓名单元的关键码keyword % m
        int startAddress = unit[i].keyword % M;
        // endAddress代表其最终储存地址,初始时两地址相等
        int endAddress = startAddress;
        // 如果哈希表上该最初地址上的查找次数为0,说明该位置并未插入关键码
        if(hashUnit[startAddress].count == 0) {
            // 将该姓名单元的关键码插入哈希表
            hashUnit[startAddress].unit.keyword = unit[i].keyword;
            // 更新哈希表上该位置的姓名
            hashUnit[startAddress].unit.name = unit[i].name;
            // 该关键码的查找次数为1
            hashUnit[startAddress].count = 1;
        }
        // 否则说明发生了"冲突"
        else {
            // 线性探测法解决冲突,sum代表总查找次数
            int sum = 0;
            // 当最终位置上的关键码不为零时继续探查
            do {
                endAddress = (endAddress + 1) % TABLE_LENGTH;
                sum++;
            } while(hashUnit[endAddress].unit.keyword != 0);
            // 找到插入位置之后,更新哈希表上的关键字名字
            hashUnit[endAddress].unit.keyword = unit[i].keyword;
            hashUnit[endAddress].unit.name =  unit[i].name;
            // 更新查找次数
            hashUnit[endAddress].count = sum + 1;
        }
    }
}

// 计算ASL值
double ASLValue(HashTable hashUnit[]) {
    double sum = 0;
    for(int i = 0; i < TABLE_LENGTH; i++) {
        // 累加查找次数不为0的项
        if(hashUnit[i].count != 0) {
            sum += hashUnit[i].count;
        }
    }
    return sum / NAME_MAX_NUM;
}

void disPlay(HashTable hashUnit[]) {
    printf("序号\t关键字\t搜索次数\tH(key)\t姓名\n");
    for (int i = 0; i < TABLE_LENGTH; i++) {
        cout << i << "\t" << hashUnit[i].unit.keyword << "\t\t" << hashUnit[i].count << "\t\t"
             << (hashUnit[i].unit.keyword) % M << "\t\t" << hashUnit[i].unit.name << endl;
    }
}


int main() {
    HashTable hashUnit[TABLE_LENGTH];
    NameList unit[30]; 
    initNameList(unit);
    creatHashTable(hashUnit , unit);
    disPlay(hashUnit);
    cout<<ASLValue(hashUnit)<<endl;
}
