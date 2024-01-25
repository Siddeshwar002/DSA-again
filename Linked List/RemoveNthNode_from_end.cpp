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

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *fast = head;
    ListNode *slow = head;
    ListNode *prev = nullptr;

    // Move the fast pointer n steps ahead
    for (int i = 0; i < n; ++i)
    {
        if (fast == nullptr)
        {
            // Handle edge case: if n is greater than the length of the list, return head
            return head;
        }
        fast = fast->next;
    }

    // Move both pointers until fast reaches the end
    while (fast != nullptr)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next;
    }

    // At this point, slow is at the nth node from the end

    if (prev == nullptr)
    {
        // If the node to be removed is the head node
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }
    else
    {
        // If the node to be removed is not the head node
        prev->next = slow->next;
        delete slow;
    }

    return head;
}
