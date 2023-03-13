/*
 * @Description:
 * @Version: 1.0
 * @Author: DaLao
 * @Email: dalao@xxx.com
 * @Date: 2021-12-23 15:07:51
 * @LastEditors: DaLao
 * @LastEditTime: 2022-09-11 22:00:21
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
using namespace std;

class Stu
{
public:
    Stu(string name, float score) : name(name), score(score) {}
    string name;
    float score;
};

class StuAdapter : public unary_function<Stu, bool>
{
private:
    string name;

public:
    explicit StuAdapter(string name) : name(name) {}

    bool operator()(const Stu &s)
    {
        return s.name == name;
    }
};

int main()
{
    vector<Stu> v;
    v.push_back(Stu("lanzhihui", 89.1));
    v.push_back(Stu("wangdan", 89.2));
    v.push_back(Stu("wangqian", 89.3));

    string str = "wangqian";

    vector<Stu>::iterator it = find_if(v.begin(), v.end(), StuAdapter(str));
    // 查找到了
    if (it != v.end())
    {
        std::cout << it->name << " " << it->score << std::endl;
    }
    return 0;
}
