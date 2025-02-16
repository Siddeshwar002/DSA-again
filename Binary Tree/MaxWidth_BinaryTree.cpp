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

int MaxWidth(node *root)
{
    int width = INT_MIN;
    queue<pair<node *, int>> q;

    if (root == NULL)
        return 0;

    q.push({root, 0});
    q.push({NULL, 0});

    int minIdx = INT_MAX;
    int maxIdx = INT_MIN;

    while (!q.empty())
    {

        if (q.front().first == NULL)
        {
            width = max(width, maxIdx - minIdx + 1);
            maxIdx = INT_MIN;
            minIdx = INT_MAX;
            q.pop();
            q.push({NULL, 0});
        }

        if (q.front().first == NULL and q.size() == 1)
            break;

        pair<node *, int> p = q.front();
        q.pop();

        minIdx = min(minIdx, p.second);
        maxIdx = max(maxIdx, p.second);

        if (p.first->left != NULL)
            q.push({p.first->left, 2 * p.second + 1});

        if (p.first->right != NULL)
            q.push({p.first->right, 2 * p.second + 2});
    }
    return width;
}

int main()
{

    // struct node *root = newNode(1);
    // root->left = newNode(3);
    // root->left->left = newNode(5);
    // root->left->left->left = newNode(7);
    // root->right = newNode(2);
    // root->right->right = newNode(4);
    // root->right->right->right = newNode(6);

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

    cout << "Ans : " << MaxWidth(root);
}