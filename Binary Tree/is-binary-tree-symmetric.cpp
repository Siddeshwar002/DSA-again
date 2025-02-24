#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

// Given a tree you need to tell if its symmetric or not
bool isSymmetricUtil(node *root1, node *root2)
{   
    // Both are NULL then return true
    // Only either of them is Null then return false
    if (root1 == NULL || root2 == NULL)
        return root1 == root2;

    // handling symmetric check
    return (root1->data == root2->data) && isSymmetricUtil(root1->left, root2->right) && isSymmetricUtil(root1->right, root2->left);
}

bool isSymmetric(node *root)
{
    if (!root)
        return true;
    return isSymmetricUtil(root->left, root->right);
}