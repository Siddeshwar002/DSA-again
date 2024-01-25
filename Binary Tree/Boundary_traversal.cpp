#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *newNode(int data)
{
    struct Node *Node = (struct Node *)malloc(sizeof(struct Node));
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return (Node);
}

void LeftBoundary(Node *root, vector<int> &v)
{
    if (!root)
        return;
    if (!root->left and !root->right)
        return;

    v.push_back(root->data);
    cout << root->data << " " << endl;
    if (root->left)
        LeftBoundary(root->left, v);
    else
        LeftBoundary(root->left, v);
    return;
}

void RightBoundary(Node *root, vector<int> &v)
{
    if (!root)
        return;
    if (!root->left and !root->right)
        return;

    v.push_back(root->data);
    cout << root->data << " " << endl;
    if (root->right)
        RightBoundary(root->right, v);
    else
        RightBoundary(root->right, v);
    return;
}

void GetLeafNodes(Node *root, vector<int> &v)
{
    if (!root)
        return;

    if (!root->left and !root->right)
    {
        v.push_back(root->data);
        cout << root->data << endl;
        return;
    }
    GetLeafNodes(root->left, v);
    GetLeafNodes(root->right, v);
}

vector<int> boundary(Node *root)
{
    vector<int> leftRes;
    vector<int> rightRes;
    vector<int> LeafRes;

    cout << "Left " << endl;
    LeftBoundary(root, leftRes);
    cout << "Right " << endl;
    RightBoundary(root, rightRes);
    cout << "Leaf " << endl;
    GetLeafNodes(root, LeafRes);

    for (auto ele : LeafRes)
        leftRes.push_back(ele);

    reverse(rightRes.begin(), rightRes.end());
    rightRes.pop_back();

    for (auto ele : rightRes)
        leftRes.push_back(ele);

    for (auto ele : leftRes)
        cout << ele << " ";
    return leftRes;
}

int main()
{
    // struct Node *root = newNode(1);
    // root->left = newNode(2);
    // root->left->left = newNode(3);
    // root->left->left->right = newNode(4);
    // root->left->left->right->left = newNode(5);
    // root->left->left->right->right = newNode(6);
    // root->right = newNode(7);
    // root->right->right = newNode(8);
    // root->right->right->left = newNode(9);
    // root->right->right->left->left = newNode(10);
    // root->right->right->left->right = newNode(11);

    Node *root = newNode(4);
    root->left = newNode(10);
    root->right = newNode(5);
    root->left->left = newNode(5);
    root->left->right = newNode(6);
    root->right->right = newNode(8);
    root->right->right->left = newNode(3);
    root->right->right->right = newNode(4);
    root->right->right->left->left = newNode(1);
    root->right->right->left->right = newNode(3);
    root->right->right->left->right->left = newNode(8);
    root->right->right->left->right->right = newNode(6);
    root->right->right->left->right->right->left = newNode(11);
    root->right->right->left->right->right->left->left = newNode(5);
    root->right->right->left->right->right->left->left->left = newNode(8);

    boundary(root);
}
