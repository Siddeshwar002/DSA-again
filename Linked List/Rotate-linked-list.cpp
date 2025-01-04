#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *rotateRight(ListNode *head, int k)
{

    // sinlge node
    if (head == nullptr || head->next == nullptr || k == 0)
        return head;

    ListNode *cur = head;
    int cnt = 0;
    while (cur != nullptr)
    {
        cur = cur->next;
        cnt++;
    }

    int rot = k % cnt;
    int p = cnt - rot;
    
    if (rot == 0)
        return head;

    ListNode *temp = head;
    ListNode *prev;
    while (p-- and temp->next != nullptr)
    {
        prev = temp;
        temp = temp->next;
    }

    ListNode *newHead = temp;
    prev->next = nullptr;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = head;

    return newHead;
}