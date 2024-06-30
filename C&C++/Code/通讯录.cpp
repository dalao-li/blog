/*
 * @Description:
 * @Version: 1.0
 * @Author: DaLao
 * @Email:  
 * @Date: 2018-04-15 09:09:32
 * @LastEditors: DaLao
 * @LastEditTime: 2022-07-19 22:03:38
 */

#include <iostream>
#include <string>
#define N 1
using namespace std;

// 建立结构体数组mes[N]
struct Info
{
    string num;
    string name;
    string sex;
    string address;
    string phone;
    string email;
    /*score[0]到score[3]分别指代数学、英语、政治、专业课的成绩, sum_score表示总成绩*/
    float score[4];
    float sum_score = 0;
    struct Info *next;
} mes[N];

int main()
{
    void input(struct Info mes[]);
    void ouput(struct Info mes[]);
    void query(struct Info mes[]);
    void modify();
    struct Info mes[N], *head, *p = mes;
    while (1)
    {
        int first_colon;
        cout << "                                            主菜单            "
                "                              "
             << endl;
        cout << "=============================================================="
                "=============================="
             << endl;
        cout << "                *一级目录:1.输入信息  2.显示信息  3.查询信息  "
                "4.修改信息  5.退出  *"
             << endl;
        cout << "=============================================================="
                "=============================="
             << endl;
        cout << "-------------------------------------一共有" << N
             << "位同学的信息------------------------------------" << endl;
        cin >> first_colon;
        switch (first_colon)
        {
        case 1:
            input(p);
            break;
        case 2:
            ouput(p);
            break;
        case 3:
            query(p);
            break;
        case 4:
            modify();
            break;
        case 5:
            exit(0); /*终止程序*/
        default:
            cout << "命令输入错误！！！" << endl;
        }
    }
    return 0;
}

/*输入函数*/
void input(struct Info mes[])
{
    struct Info *p;
    for (int i = 0, p = mes; p < mes + N; p++, i++)
    {
        cout << "第" << i + 1 << "位成员:" << endl;
        cout << "请输入第" << i + 1 << "位成员的学号:";
        cin >> p->num;
        cout << "请输入第" << i + 1 << "位成员的姓名:";
        cin >> p->name;
        cout << "请输入第" << i + 1 << "位成员的性别:";
        cin >> p->sex;
        cout << "请输入第" << i + 1 << "位成员的家庭住址:";
        cin >> p->address;
        cout << "请输入第" << i + 1 << "位成员的电话号码:";
        cin >> p->phone;
        cout << "请输入第" << i + 1 << "位成员的电子邮箱:";
        cin >> p->email;
        cout << "请输入第" << i + 1 << "名学生的数学成绩:";
        cin >> p->score[0];
        cout << "请输入第" << i + 1 << "名学生的英语成绩:";
        cin >> p->score[1];
        cout << "请输入第" << i + 1 << "名学生的政治成绩:";
        cin >> p->score[2];
        cout << "请输入第" << i + 1 << "名学生的专业课成绩:";
        cin >> p->score[3];
        for (int j = 0; j < 4; j++)
        {
            p->sum_score = p->sum_score + p->score[j];
        }
    }
}

/*显示函数*/
void ouput(struct Info mes[])
{
    int i, number, third_colon, forth_colon, sign = 1, wign = 1;
    struct Info *head, *p;
    p = mes;
    /*建立链表*/
    head = p; /*将第一个元素的地址放入头指针中*/
    for (i = 0; i < N - 1; i++)
    { /*依次将后一个元素的地址放入前一个元素的next成员中*/
        (p + i)->next = (p + i + 1);
    }
    (p + N - 1)->next = NULL; /*最后一个元素的next中放入NULL*/
    cout << "                                                          " << endl;
    while (sign)
    {
        cout << "--------------------------------------------------------------"
                "-------------------------------------"
             << endl;
        cout << "       **二级目录:显示输入结果  1.个人信息显示  "
                "2.全部信息显示  3.显示成绩  4.退出显示"
             << endl;
        cout << "--------------------------------------------------------------"
                "-------------------------------------"
             << endl;
        cin >> third_colon;
        switch (third_colon)
        {
        case 1:
            cout << "请输入想显示的人员的序号:";
            cin >> number;
            if (number > N || number < 1)
            {
                cout << "查无此人, 错误！！！:" << endl;
                break;
            }
            cout << "第" << number << "位成员的学号为:    "
                 << (p + number - 1)->num << endl;
            cout << "第" << number << "位成员的姓名为:    "
                 << (p + number - 1)->name << endl;
            cout << "第" << number << "位成员的性别为:    "
                 << (p + number - 1)->sex << endl;
            cout << "第" << number << "位成员的家庭住址为:"
                 << (p + number - 1)->address << endl;
            cout << "第" << number << "位成员的电话号码为:"
                 << (p + number - 1)->phone << endl;
            cout << "第" << number << "位成员的电子邮箱为:"
                 << (p + number - 1)->email << endl;
            cout << "第" << number << "位成员的数学成绩为:"
                 << (p + number - 1)->score[0] << "分" << endl;
            cout << "第" << number << "位员的英语成绩为:"
                 << (p + number - 1)->score[1] << "分" << endl;
            cout << "第" << number << "位成员的政治成绩为:"
                 << (p + number - 1)->score[2] << "分" << endl;
            cout << "第" << number << "位成员的专业成绩为:"
                 << (p + number - 1)->score[3] << "分" << endl;
            cout << "第" << number << "位成员的总成绩为:  "
                 << (p + number - 1)->sum_score << "分" << endl;
            cout << "第" << number << "位成员的平均成绩为:"
                 << (p + number - 1)->sum_score / 4 << "分" << endl;
            cout << "                                                      "
                    "    "
                 << endl;

            break;
        case 2:
            for (i = 0; head != NULL; i++)
            {
                cout << "第" << i + 1 << "位成员的学号为:    " << head->num
                     << endl;
                cout << "第" << i + 1 << "位成员的姓名为:    "
                     << head->name << endl;
                cout << "第" << i + 1 << "位成员的性别为:    " << head->sex
                     << endl;
                cout << "第" << i + 1 << "位成员的家庭住址为:"
                     << head->address << endl;
                cout << "第" << i + 1 << "位成员的电话号码为:"
                     << head->phone << endl;
                cout << "第" << i + 1 << "位成员的电子邮箱为:"
                     << head->email << endl;
                cout << "第" << i + 1 << "位成员的数学成绩为:"
                     << head->score[0] << "分" << endl;
                cout << "第" << i + 1 << "位成员的英语成绩为:"
                     << head->score[1] << "分" << endl;
                cout << "第" << i + 1 << "位成员的政治成绩为:"
                     << head->score[2] << "分" << endl;
                cout << "第" << i + 1 << "位成员的专业成绩为:"
                     << head->score[3] << "分" << endl;
                cout << "第" << i + 1 << "位成员的总成绩为:  "
                     << head->sum_score << "分" << endl;
                cout << "第" << i + 1 << "位成员的平均成绩为:"
                     << head->sum_score / 4 << "分" << endl;
                cout << "                               " << endl;
                head = head->next; /*head指向下一节点*/
            }
            break;
        case 3:
            while (wign)
            {
                cout << "      ***三级目录:查看全部人的单科成绩  1.数学 "
                        "2.英语 3.政治 4.专业成绩 5.总成绩 6.退出"
                     << endl;
                cout << "      "
                        "--------------------------------------------------"
                        "--------------------------------"
                     << endl;
                cin >> forth_colon;
                switch (forth_colon)
                {
                case 1:
                    for (i = 0, p = mes; p < mes + N; p++, i++)
                    {
                        cout << "第" << i + 1 << "位成员的数学成绩为:"
                             << p->score[0] << "分" << endl;
                        cout << "                                      "
                                "            "
                             << endl;
                    }
                    break;
                case 2:
                    for (i = 0, p = mes; p < mes + N; p++, i++)
                    {
                        cout << "第" << i + 1 << "位成员的英语成绩为:"
                             << p->score[1] << "分" << endl;
                        cout << "                                      "
                                "            "
                             << endl;
                    }
                    break;
                case 3:
                    for (i = 0, p = mes; p < mes + N; p++, i++)
                    {
                        cout << "第" << i + 1 << "位成员的政治成绩为:"
                             << p->score[2] << "分" << endl;
                        cout << "                                      "
                                "            "
                             << endl;
                    }
                    break;
                case 4:
                    for (i = 0, p = mes; p < mes + N; p++, i++)
                    {
                        cout << "第" << i + 1 << "位成员的专业成绩为:"
                             << p->score[3] << "分" << endl;
                        cout << "                                      "
                                "            "
                             << endl;
                    }
                    break;
                case 5:
                    for (i = 0, p = mes; p < mes + N; p++, i++)
                    {
                        cout << "第" << i + 1 << "位成员的总成绩为:"
                             << p->score[4] << "分" << endl;
                        cout << "                                      "
                                "          "
                             << endl;
                    }
                    break;
                case 6:
                    wign = 0;
                    break;
                default:
                    cout << "命令输入错误！！！" << endl;
                }
            }
            break;
        case 4:
            sign = 0;
            break;
        default:
            cout << "命令输入错误！！！" << endl;
        }
    }
}

/*信息查询函数*/
void query(struct Info mes[])
{
    struct Info *p = mes;
    string num_or_name;
    int colon, second_colon, third_colon, forth_colon, sign = 1, i, k,
                                                       max_score[4], max_sum;
    while (sign)
    {
        cout << "二级目录  1.按学号或姓名查找 2.查询最大成绩  3.花名册  4.退出"
             << endl;
        cin >> third_colon;
        switch (third_colon)
        {
        case 1:
            cout << "请输入姓名或学号开始查找"
                 << " ";
            cin >> num_or_name;
            for (i = 0; p < mes + N; p++, i++)
            {
                if ((p->name == num_or_name) || (p->name == num_or_name))
                {
                    cout << "该为成员的序号为:" << i + 1 << endl;
                    cout << "该位成员的学号为:    " << p->num << endl;
                    cout << "该位成员的姓名为:    " << p->name << endl;
                    cout << "该位成员的性别为:    " << p->sex << endl;
                    cout << "该位成员的家庭住址为:" << p->address << endl;
                    cout << "该位成员的电话号码为:" << p->phone << endl;
                    cout << "该位成员的电子邮箱为:" << p->email << endl;
                    cout << "该位成员的数学成绩为:" << p->score[0] << "分"
                         << endl;
                    cout << "该位成员的英语成绩为:" << p->score[1] << "分"
                         << endl;
                    cout << "该位成员的政治成绩为:" << p->score[2] << "分"
                         << endl;
                    cout << "该位成员的专业成绩为:" << p->score[3] << "分"
                         << endl;
                    cout << "该位成员的总成绩为:  " << p->sum_score << "分"
                         << endl;
                    cout << "该位成员的平均成绩为:" << p->sum_score / 4
                         << "分" << endl;
                    cout << "                                            "
                         << endl;
                }
                else if (i == N)
                {
                    cout << "未查询到匹配的记录！" << endl;
                    break;
                }
            };
            break;
        case 2:
            max_sum = p->sum_score;
            for (i = 0; i < 5; i++)
            {
                max_score[i] = p->score[i];
            }
            while (sign)
            {
                cout << "--------------------------------------------------"
                        "-----------------------------------------"
                     << endl;
                cout << "        **三级目录:输入代表数字查找最大成绩: "
                        "1.数学 2.英语 3.政治 4.专业课 5.总成绩 6.退出"
                     << endl;
                cout << "--------------------------------------------------"
                        "-----------------------------------------"
                     << endl;
                cin >> second_colon;
                switch (second_colon)
                {
                case 1:
                    for (k = 0, i = 1; i < N;
                         i++)
                    { /*找出数学的最大成绩*/
                        if ((p + i)->score[0] >= p->score[0])
                        {
                            max_score[0] = (p + i)->score[0];
                            k = i;
                        }
                    }
                    cout << "数学最高成绩为:" << (p + k)->score[0]
                         << "分" << endl;
                    cout << "该名学生是:" << (p + k)->name << endl;
                    cout << "                                 " << endl;
                    break;
                case 2:
                    for (k = 0, i = 1; i < N;
                         i++)
                    { /*找出英语的最大成绩*/
                        if ((p + i)->score[1] >= max_score[1])
                        {
                            max_score[1] = (p + i)->score[1];
                            k = i;
                        }
                    }
                    cout << "英语最高成绩为:" << (p + k)->score[1]
                         << "分" << endl;
                    cout << "该名学生是:" << (p + k)->name << endl;
                    cout << "                                 " << endl;
                    break;
                case 3:
                    for (k = 0, i = 1; i < N;
                         i++)
                    { /*找出政治的最大成绩*/
                        if ((p + i)->score[2] >= max_score[2])
                        {
                            max_score[2] = (p + i)->score[2];
                            k = i;
                        }
                    }
                    cout << "政治最高成绩为:" << (p + k)->score[2]
                         << "分" << endl;
                    cout << "该名学生是:" << (p + k)->name << endl;
                    cout << "                                 " << endl;
                    break;
                case 4:
                    for (k = 0, i = 1; i < N;
                         i++)
                    { /*找出专业课的最大成绩*/
                        if ((p + i)->score[3] >= max_score[3])
                        {
                            max_score[3] = (p + i)->score[3];
                            k = i;
                        }
                    }
                    cout << "专业课最高成绩为:" << (p + k)->score[3]
                         << "分" << endl;
                    cout << "该名学生是:" << (p + k)->name << endl;
                    cout << "                                 " << endl;
                    break;
                case 5:
                    for (k = 0, i = 1; i < N;
                         i++)
                    { /*找出总成绩最大的人*/
                        if ((p + i)->sum_score >= max_sum)
                        {
                            max_sum = (p + i)->sum_score;
                            k = i;
                        }
                    }
                    cout << "总成绩最高为:" << (p + k)->score[4]
                         << "分" << endl;
                    cout << "该名学生是:" << (p + k)->name << endl;
                    cout << "                                 " << endl;
                    break;
                case 6:
                    sign = 0;
                    break;
                default:
                    cout << "命令输入错误！！！" << endl;
                }
            }
            break;
        case 3:
            for (i = 0, p = mes; p < mes + N; i++, p++)
            {
                cout << "第" << i + 1 << "位成员:" << p->name << endl;
            }
            break;
        case 4:
            sign = 0;
            break;
        default:
            cout << "命令输入错误！！！" << endl;
        }
    }
}

/*修改信息函数*/
void modify()
{
    string key1, key = "123456"; //设置修改密码
    struct Info *p;
    p = mes;
    int number, j, sign = 1, k = 3;
    cout << "                                              " << endl;
    while (sign)
    { //设置修改密码, 三次错误直接结束程序
        cout << "请输入修改密码"
             << " ";
        cin >> key1;
        if (key1 == key)
            break;
        else
        {
            cout << "密码错误, 你还可以输入" << k - 1 << "次";
            k--;
            if (k == 0)
                exit(0);
        }
    }
    cout << "请输入需要修改信息的成员编号:"; /*确保不超出范围*/
    while (sign)
    {
        cin >> number;
        if (number > N)
        {
            cout << "该学生信息不存在！！！请重新输入" << endl;
        }
        else
            break;
    }
    cout << "修改信息的成员为第:" << number << "位" << endl;
    cout << "请重新输入该位成员的学号: ("
         << "原数据为:" << (p + number - 1)->num << ")" << endl;
    cin >> (p + number - 1)->num;
    cout << "请重新输入该位成员的姓名:("
         << "原数据为:" << (p + number - 1)->name << ")" << endl;
    cin >> (p + number - 1)->name;
    cout << "请重新输入该位成员的性别:("
         << "原数据为:" << (p + number - 1)->sex << ")" << endl;
    cin >> (p + number - 1)->sex;
    cout << "请重新输入该位成员的家庭住址:("
         << "原数据为:" << (p + number - 1)->address << ")" << endl;
    cin >> (p + number - 1)->address;
    cout << "请重新输入该位成员的电话号码:("
         << "原数据为:" << (p + number - 1)->phone << ")" << endl;
    cin >> (p + number - 1)->phone;
    cout << "请重新输入该位成员的电子邮箱:("
         << "原数据为:" << (p + number - 1)->email << ")" << endl;
    cin >> (p + number - 1)->email;
    cout << "请重新输入该位学生的数学成绩:"
         << "原数据为:" << (p + number - 1)->score[0] << ")" << endl;
    cin >> (p + number - 1)->score[0];
    cout << "请重新输入该位学生的英语成绩:("
         << "原数据为:" << (p + number - 1)->score[1] << ")" << endl;
    cin >> (p + number - 1)->score[1];
    cout << "请重新输入该位学生的政治成绩:("
         << "原数据为:" << (p + number - 1)->score[2] << ")" << endl;
    cin >> (p + number - 1)->score[2];
    cout << "请重新输入该位学生的专业课成绩:("
         << "原数据为:" << (p + number - 1)->score[3] << ")" << endl;
    cin >> (p + number - 1)->score[3];
    p->sum_score = 0;
    for (j = 0; j < 4; j++)
    {
        (p + number - 1)->sum_score = p->sum_score + (p + number - 1)->score[j];
    }
}
