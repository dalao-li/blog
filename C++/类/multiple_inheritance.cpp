/*
 * @Description: 
 * @Version: 1.0
 * @Author: dalao
 * @Email: dalao_li@163.com
 * @Date: 2022-04-19 22:10:48
 * @LastEditors: DaLao
 * @LastEditTime: 2022-05-24 23:06:46
 */


#include<iostream>
#include<string>


class People {
    public:
        People() {}

        People(int age , std::string name) {
            this->m_age = age;
            this->m_name = name;
        }

        ~People() {}

        virtual void display() = 0;

    protected:
        int m_age;
        std::string m_name;
};


class Student : public People {
    public:
        Student() {}

        Student(int age , std::string name , std::string num) : People(age , name) {
            this->m_num = num;
        }

        void display() {
            std::cout << "age:" << m_age << "\nname:" << m_name << "\nnum" << m_num << std::endl;
        }
        ~Student() {}
    
    private:
        std::string m_num;
}; 


int main() {
    Student stu = Student(20 , "LILI" , "100-AX");
    stu.display();

    return 0;
}