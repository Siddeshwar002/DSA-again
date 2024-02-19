#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

node *previous = NULL;

void flatten(node *root)
{
    if (root == NULL)
        return;

    flatten(root->right);
    flatten(root->left);

    root->right = previous;
    root->left = NULL;
    previous = root;
}
