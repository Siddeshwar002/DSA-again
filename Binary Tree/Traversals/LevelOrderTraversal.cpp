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

// ! BFS
// ! Without using NULL
// ! Small Code ++ Smart coding

vector<int> levelOrder(node *root)
{
    vector<int> ans;

    if (root == NULL)
        return ans;

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        ans.push_back(temp->data);

        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);

    }
    return ans;
}