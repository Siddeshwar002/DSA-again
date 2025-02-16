#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// $ *****************************************************************************************************************
// Approach 1 :
// Accepted

class Solution
{
public:
    pair<bool, TreeNode *> solve(TreeNode *root, int limit, int Sum)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            Sum += root->val;
            if (Sum < limit)
                return {0, NULL};
            else
                return {1, root};
        }

        Sum += root->val;

        pair<int, TreeNode *> left, right;

        if (root->left != nullptr)
            left = solve(root->left, limit, Sum);
        if (root->right != nullptr)
            right = solve(root->right, limit, Sum);

        if (root->left != nullptr)
            root->left = left.second;
        if (root->right != nullptr)
            root->right = right.second;

        bool flag = ((root->left != nullptr && left.first) || (root->right != nullptr && right.first));

        if (flag)
            return {flag, root};
        else
            return {flag, NULL};
    }
    TreeNode *sufficientSubset(TreeNode *root, int limit)
    {
        auto res = solve(root, limit, 0);
        return res.second;
    }
};

// $*****************************************************************************************************************

// Approach 2 :
// Smart Approch
// Accepted

class Solution
{
public:
    TreeNode *sufficientSubset(TreeNode *root, int limit)
    {
        if (!root)
            return nullptr;

        if (!root->left && !root->right)
        {
            return root->val < limit ? nullptr : root;
        }

        // Recursively prune left and right subtrees
        root->left = sufficientSubset(root->left, limit - root->val);
        root->right = sufficientSubset(root->right, limit - root->val);

        // If both left and right subtrees are pruned, this node becomes insufficient
        if (!root->left && !root->right)
            return nullptr;

        return root;
    }
};