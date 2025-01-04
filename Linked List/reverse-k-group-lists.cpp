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

ListNode *reverseKGroupHelper(ListNode *head, int k, int &curLen)
{
    if (curLen < k)
        return head;

    ListNode *prev = nullptr;
    ListNode *cur = head;
    ListNode *next = nullptr;

    for (int i = 0; i < k; i++)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    curLen -= k;
    head->next = reverseKGroupHelper(cur, k, curLen);
    return prev;
}

ListNode *reverseKGroup(ListNode *head, int k)
{

    int len = 1;
    ListNode *cur = head;

    // base case
    if (head == nullptr or k == 0)
        return head;

    // find the length of the entire list
    while (cur != nullptr and cur->next != nullptr)
    {
        len++;
        cur = cur->next;
    }
    cout << len;

    // reversing
    return reverseKGroupHelper(head, k, len);
}
