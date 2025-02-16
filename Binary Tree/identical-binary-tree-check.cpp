#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

// two trees are being compared
bool isIdentical(node *node1, node *node2)
{
    // both are NULL they are same
    if (node1 == NULL && node2 == NULL)
        return true;

    // only one among them is NULL
    else if (node1 == NULL || node2 == NULL)
        return false;

    return ((node1->data == node2->data) && isIdentical(node1->left, node2->left) && isIdentical(node1->right, node2->right));
}