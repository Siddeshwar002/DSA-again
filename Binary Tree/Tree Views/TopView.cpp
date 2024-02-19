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
void TopView(node *root, int idx, map<int, int> &mp)
{
    if (root == NULL)
        return;

    // Difference between top and bottom view
    if (!mp[idx])
    {
        mp[idx] = root->data;
        cout << root->data << " ";
    }

    TopView(root->left, idx - 1, mp);
    TopView(root->right, idx + 1, mp);
}

// *****************************************************************************************
// BFS method
// O(N)

class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(node *root)
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

            // do not update if already added a value
            // Diff betweeen TOP and BOTTOM
            if (mpp.find(line) == mpp.end())
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