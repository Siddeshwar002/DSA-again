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

ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *cur = head;

    bool flag = true;

    while ((fast != nullptr and fast->next != nullptr and fast->next->next != nullptr) and (slow != fast or flag))
    {
        flag = false;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast == nullptr || fast->next == nullptr || fast->next->next == nullptr)
        return nullptr;

    if (fast == slow and slow == head)
        return head;

    slow = head;

    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

// ! ****************************************************************************************
// ! Better Code

ListNode *detectCycle_2(ListNode *head)
{
    // Initialize two pointers, slow and fast, to the head of the linked list.
    ListNode *slow = head;
    ListNode *fast = head;

    // Move the slow pointer one step and the fast pointer two steps at a time through the linked list,
    // until they either meet or the fast pointer reaches the end of the list.
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            // If the pointers meet, there is a cycle in the linked list.
            // Reset the slow pointer to the head of the linked list, and move both pointers one step at a time
            // until they meet again. The node where they meet is the starting point of the cycle.
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }

    // If the fast pointer reaches the end of the list without meeting the slow pointer,
    // there is no cycle in the linked list. Return nullptr.
    return nullptr;
}