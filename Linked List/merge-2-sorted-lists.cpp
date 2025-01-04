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

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    // Base cases: if either list is empty, return the other list
    if (list1 == nullptr)
    {
        return list2;
    }
    else if (list2 == nullptr)
    {
        return list1;
    }

    // Compare the values of the nodes in both lists
    if (list1->val <= list2->val)
    {
        // If the value in list1 is smaller or equal, connect list1 to the merged list
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    else
    {
        // Otherwise, connect list2 to the merged list
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}