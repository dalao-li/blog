/*
 * @Description:
 * @Version: 1.0
 * @Author: dalao
 * @Email:  
 * @Date: 2022-04-04 22:12:44
 * @LastEditors: DaLao
 * @LastEditTime: 2022-09-11 17:59:25
 */

#include <iostream>

// 哈希表表长
const int TABLE_LENGTH = 50;

// 人名最大个数
const int NAME_MAX_NUM = 30;

// 除数
const int M = 47;

typedef struct
{
    // 用户的名字
    std::string name;
    // 该名字所对应的关键字
    int keyword;
} NameList;

typedef struct
{
    NameList unit;
    // 查找次数
    int count;
} HashTable;

void init(NameList unit[])
{
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

    for (int i = 0; i < NAME_MAX_NUM; i++)
    {
        // sum代表该人名字各字符的ASCLL码值之和
        int sum = 0;
        for (int j = 0; j < unit[i].name.size(); j++)
        {
            sum += unit[i].name[j];
        }
        // 更新关键字
        unit[i].keyword = sum;
    }
}

// 建立哈希表, m为散列函数中的被除数
void create(HashTable hash_unit[], NameList unit[])
{
    // 哈希表初始化
    for (int i = 0; i < TABLE_LENGTH; i++)
    {
        hash_unit[i].unit.name = "";
        hash_unit[i].unit.keyword = 0;
        hash_unit[i].count = 0;
    }

    // 构建哈希表, 遍历每一个姓名单元, 将它们插入到哈希表上去
    for (int i = 0; i < NAME_MAX_NUM; i++)
    {
        // startAddress代表该姓名单元最初储存地址, 其值为姓名单元的关键码keyword % m
        int startAddress = unit[i].keyword % M;
        // endAddress代表其最终储存地址, 初始时两地址相等
        int endAddress = startAddress;
        // 如果哈希表上该最初地址上的查找次数为0, 说明该位置并未插入关键码
        if (hash_unit[startAddress].count == 0)
        {
            // 将该姓名单元的关键码插入哈希表
            hash_unit[startAddress].unit.keyword = unit[i].keyword;
            // 更新哈希表上该位置的姓名
            hash_unit[startAddress].unit.name = unit[i].name;
            // 该关键码的查找次数为1
            hash_unit[startAddress].count = 1;
        }
        // 否则说明发生了"冲突"
        else
        {
            // 线性探测法解决冲突, sum代表总查找次数
            int sum = 0;
            // 当最终位置上的关键码不为零时继续探查
            do
            {
                endAddress = (endAddress + 1) % TABLE_LENGTH;
                sum++;
            } while (hash_unit[endAddress].unit.keyword != 0);
            // 找到插入位置之后, 更新哈希表上的关键字名字
            hash_unit[endAddress].unit.keyword = unit[i].keyword;
            hash_unit[endAddress].unit.name = unit[i].name;
            // 更新查找次数
            hash_unit[endAddress].count = sum + 1;
        }
    }
}

// 计算ASL值
double ASLValue(HashTable hash_unit[])
{
    double sum = 0;
    for (int i = 0; i < TABLE_LENGTH; i++)
    {
        // 累加查找次数不为0的项
        if (hash_unit[i].count != 0)
        {
            sum += hash_unit[i].count;
        }
    }
    return sum / NAME_MAX_NUM;
}

void print(HashTable hash_unit[])
{
    std::cout << "序号\t关键字\t搜索次数\tH(key)\t姓名" << std::endl;
    for (int i = 0; i < TABLE_LENGTH; i++)
    {
        std::cout << i << "\t";
        std::cout << hash_unit[i].unit.keyword << "\t\t";
        std::cout << hash_unit[i].count << "\t\t";
        std::cout << (hash_unit[i].unit.keyword) % M << "\t\t";
        std::cout << hash_unit[i].unit.name << std::endl;
    }
}

int main()
{
    HashTable hash_unit[TABLE_LENGTH];
    NameList unit[30];

    init(unit);

    create(hash_unit, unit);

    print(hash_unit);

    std::cout << ASLValue(hash_unit) << std::endl;
}
