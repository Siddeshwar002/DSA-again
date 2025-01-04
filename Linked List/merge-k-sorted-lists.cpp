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

ListNode *merge2SortedLists(ListNode *l1, ListNode *l2)
{
    if (l1 == nullptr)
        return l2;
    if (l2 == nullptr)
        return l1;

    if (l1->val <= l2->val)
    {
        l1->next = merge2SortedLists(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = merge2SortedLists(l1, l2->next);
        return l2;
    }
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    ListNode *ans = nullptr;

    if (lists.size() == 0)
        return ans;

    while (lists.size() > 1)
    {
        ListNode *l1 = lists.back();
        lists.pop_back();
        ListNode *l2 = lists.back();
        lists.pop_back();

        ListNode *l3 = merge2SortedLists(l1, l2);
        lists.push_back(l3);
    }

    return lists[0];
}