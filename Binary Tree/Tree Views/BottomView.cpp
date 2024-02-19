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

// Recursive code
// TC : O(N)
void BottomView(node *root, int idx, map<int, int> &mp)
{
    if (root == NULL)
        return;

    BottomView(root->left, idx - 1, mp);
    BottomView(root->right, idx + 1, mp);

    if (!mp[idx])
    {
        mp[idx] = root->data;
        cout << root->data << " ";
    }
}

// *****************************************************************************************
// BFS method
// O(N)

class Solution
{
public:
    vector<int> bottomView(node *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        map<int, int> mpp;
        queue<pair<node *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            node *node = it.first;
            int line = it.second;
            mpp[line] = node->data;

            if (node->left != NULL)
            {
                q.push({node->left, line - 1});
            }
            if (node->right != NULL)
            {
                q.push({node->right, line + 1});
            }
        }

        for (auto it : mpp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};

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

    map<int, int> mp;
    BottomView(root, 0, mp);
}