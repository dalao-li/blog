/*
 * @Description: 
 * @Version: 1.0
 * @Author: dalao
 * @Email: dalao_li@163.com
 * @Date: 2022-04-19 22:10:48
 * @LastEditors: dalao
 * @LastEditTime: 2022-04-19 22:17:49
 */


#include<iostream>
#include<string>

using namespace std;

class People {
    public:
        People() {}

        People(int a , std::string n) {
            age = a;
            name = n;
        }
        
        void setValue(int age , std::string name) {
            this->age = age;
            this->name = name;
        } 
        virtual void display() = 0;
        ~People() {}
    
    protected:
        int age;
        std::string name;
};


class Student : public People {
    public:
        Student() {}

        Student(int a , std::string n , std::string b) : People(a , n) , ID(b) {}
        void setID(std::string ID) {
            this->ID = ID;
        }

        void display() {
            printf("age = %d\nname = %s\nID = %d\n" , age , name , ID);
        }
        ~Student() {}
    
    private:
        std::string ID;
}; 

class Teacher:public People {
    public:
        Teacher() {}
        Teacher(int a , std::string n , std::string b):People(a , n) , ID(b){}
        void setID(std::string ID) {
            this->ID = ID;
        }
        void display() {
            printf("age = %d\nname = %s\nID = %d\n" , age , name , ID);
        }
        ~Teacher() {}
    
    private:
        std::string ID;
};

int main() {
    Student *p1 , stu;
    Teacher *p2 , tea;
    p1 = &stu;
    p1->setValue(20 , "LILI");
    p1->setID("1009");
    p1->display();
    
    p2 = &tea;
    p2->setValue(30 , "WANG");
    p2->setID("2001");
    p2->display();
    return 0;
}