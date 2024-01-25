#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

Node *Merge2SortedLists(Node *l1, Node *l2)
{
    if (l1 == nullptr)
        return l2;

    if (l2 == nullptr)
        return l1;

    if (l1->data <= l2->data)
    {
        l1->bottom = Merge2SortedLists(l1->bottom, l2);
        return l1;
    }
    else
    {
        l2->bottom = Merge2SortedLists(l1, l2->bottom);
        return l2;
    }
}

Node *flatten(Node *root)
{
    Node *l1 = root;
    Node *l2 = root->next;

    while (l2)
    {
        l1 = Merge2SortedLists(l1, l2);
        l2 = l2->next;
    }

    return l1;
}