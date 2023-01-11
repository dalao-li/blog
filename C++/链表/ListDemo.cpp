#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int main(void)
{
    ListNode *p = new ListNode(5);

    ListNode *q = new ListNode(6);

    p->next = q;

    ListNode *x = p;

    while (x)
    {
        std::cout << x->val << std::endl;
        x = x->next;
    }

    return 0;
}