/*
 * @Description:
 * @Version: 1.0
 * @Author: DaLao
 * @Email:
 * @Date: 2021-12-23 15:07:51
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2024-07-01 16:43:06
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

class Student
{
public:
    Student(std::string name, float score) : name(name), score(score) {}

    std::string name;
    float score;
};

class StuAdapter : public std::unary_function<Student, bool>
{
private:
    std::string name;

public:
    explicit StuAdapter(std::string name) : name(name) {}

    bool operator()(const Student &s)
    {
        return s.name == name;
    }
};

int main()
{
    std::vector<Student> v{Student("A", 89.1), Student("B", 89.2), Student("C", 89.3)};

    std::string name = "A";
    std::vector<Student>::iterator it = find_if(v.begin(), v.end(), StuAdapter(name));
    if (it != v.end())
    {
        std::cout << it->name << " " << it->score << std::endl;
    }
    else
    {
        std::cout << "not found" << std::endl;
    }
    return 0;
}
