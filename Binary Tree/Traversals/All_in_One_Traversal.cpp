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

void AllTraversals(node *root, vector<int> &Preorder, vector<int> &Inorder, vector<int> &PostOrder)
{
    if (root == NULL)
        return;
    
    // 1. PreOrder
    Preorder.push_back(root->data);

    AllTraversals(root->left, Preorder, Inorder, PostOrder);
    
    // 2. Inorder
    Inorder.push_back(root->data);
    
    AllTraversals(root->right, Preorder, Inorder, PostOrder);
    
    // 3. PostOrder
    PostOrder.push_back(root->data);
    return;
}

int main()
{

    // struct node *root = newNode(1);
    // root->left = newNode(2);
    // root->right = newNode(3);
    // root->left->left = newNode(4);
    // root->left->right = newNode(5);
    // root->left->right->left = newNode(8);
    // root->right->left = newNode(6);
    // root->right->right = newNode(7);
    // root->right->right->left = newNode(9);
    // root->right->right->right = newNode(10);

    struct node *root = newNode(1);
    root->left = newNode(2);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right = newNode(3);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    vector<int> PreOrder;
    vector<int> InOrder;
    vector<int> PostOrder;

    AllTraversals(root, PreOrder, InOrder, PostOrder);

    for (auto v : PreOrder)
        cout << v << " ";

    cout << endl;

    for (auto v : InOrder)
        cout << v << " ";

    cout << endl;

    for (auto v : PostOrder)
        cout << v << " ";

    return 0;
}