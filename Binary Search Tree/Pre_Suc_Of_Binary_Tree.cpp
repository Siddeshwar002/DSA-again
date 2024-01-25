#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        key = x;
        left = NULL;
        right = NULL;
    }
};

void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)

{

    if (!root)
        return;

    if (key == root->key)
    {

        if (root->left)
        {

            Node *temp = root->left;

            while (temp->right)
            {
                temp = temp->right;
            }
            pre = temp;
        }

        if (root->right)
        {

            Node *temp = root->right;

            while (temp->left)
            {
                temp = temp->left;
            }
            suc = temp;
        }
        return;
    }

    if (key < root->key)
    {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }

    else if (key > root->key)
    {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
}