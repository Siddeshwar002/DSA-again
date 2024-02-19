#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}

// * Pre Order
void preOrderTrav(node *curr, vector<int> &preOrder)
{
    if (curr == NULL)
        return;

    preOrder.push_back(curr->data);
    preOrderTrav(curr->left, preOrder);
    preOrderTrav(curr->right, preOrder);
}

// * In Order
void inOrderTrav(node *curr, vector<int> &inOrder)
{
    if (curr == NULL)
        return;

    inOrderTrav(curr->left, inOrder);
    inOrder.push_back(curr->data);
    inOrderTrav(curr->right, inOrder);
}

// * Post Order
void postOrderTrav(node *curr, vector<int> &postOrder)
{
    if (curr == NULL)
        return;

    postOrderTrav(curr->left, postOrder);
    postOrderTrav(curr->right, postOrder);
    postOrder.push_back(curr->data);
}

int main()
{

    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(8);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->right->left = newNode(9);
    root->right->right->right = newNode(10);

    vector<int> inOrder;
    inOrderTrav(root, inOrder);
}