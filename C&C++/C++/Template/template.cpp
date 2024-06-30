/*
 * @Description:
 * @Version: 1.0
 * @Author: dalao
 * @Email:  
 * @Date: 2022-04-18 18:45:30
 * @LastEditors: DaLao
 * @LastEditTime: 2022-05-24 22:42:51
 */

#include <iostream>
#include <vector>

template <typename T>
T add(T a, T b)
{
    return a + b;
}

template <typename T>
struct Node
{
    T data;
    Node<T> *next;
};

template <typename T>
void display(Node<T> *&head, std::vector<T> &v)
{
    Node<T> *tail = head;
    for (int i = 0; i < v.size(); i++)
    {
        Node<T> *p = new Node<T>;
        p->data = v[i];
        p->next = NULL;
        // 新节点位于尾指针的后边
        tail->next = p;
        // 更新尾指针的位置
        tail = p;
    }
    Node<T> *p = head->next;
    while (p)
    {
        std::cout << p->data << " ";
        p = p->next;
    }
    printf("\n");
}

template <typename T>
class Composer
{
public:
    Composer(T a, T b)
    {
        x = a;
        y = b;
    }
    void display();

private:
    T x;
    T y;
};

template <typename T>
void Composer<T>::display()
{
    std::cout << (x > y ? x : y) << " " << (x < y ? x : y) << std::endl;
}

int main(void)
{
    std::cout << add<int>(1, 2) << std::endl;

    std::cout << add(2.4, 3.5) << std::endl;

    std::cout << add<std::string>("I am", "a student.") << std::endl;

    std::vector<int> v1 = {1, 2, 3, 4, 5};

    std::vector<double> v2 = {1.1, 2.2, 3.3, 4.4, 5.5};

    std::vector<std::string> v3 = {"aaaa", "b", "c", "d", "e"};

    Node<int> *p1 = new Node<int>;

    Node<double> *p2 = new Node<double>;

    Node<std::string> *p3 = new Node<std::string>;

    // 1 2 3 4 5
    display<int>(p1, v1);

    // 1.1 2.2 3.3 4.4 5.5
    display<double>(p2, v2);

    // a b c d e
    display<std::string>(p3, v3);

    Composer<int> cmp1(3, 7);

    cmp1.display();

    Composer<double> cmp2(3.333, 7.777);

    cmp2.display();

    Composer<char> cmp3('a', 'A');

    cmp3.display();

    return 0;
}