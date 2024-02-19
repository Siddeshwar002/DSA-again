#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Naive solution
// accepted
class Solution
{
public:
    void solve(TreeNode *root, int g1, int g2, int &ans)
    {
        if (root == nullptr)
            return;

        if (g1 == 0 || g2 == 0)
            ans += root->val;

        // These two conditions
        if (g1 <= 0 && root->val % 2 == 0)
            g1 = 2;
        if (g1 == 1 && root->val % 2 == 0)
            g2 = 2;

        solve(root->left, g1 - 1, g2 - 1, ans);
        solve(root->right, g1 - 1, g2 - 1, ans);
        return;
    }

    int sumEvenGrandparent(TreeNode *root)
    {
        int ans = 0;
        solve(root, -1, -1, ans);
        return ans;
    }
};

// Super code
// Accepted

// Passing grandparent and parent

class Solution
{
public:
    void solve(TreeNode *root, TreeNode *parent, TreeNode *grandparent, int &ans)
    {
        if (!root)
            return;

        if (grandparent && grandparent->val % 2 == 0)
        {
            ans += root->val;
        }

        solve(root->left, root, parent, ans);
        solve(root->right, root, parent, ans);
    }

    int sumEvenGrandparent(TreeNode *root)
    {
        if (!root)
            return 0;
        int ans = 0;
        solve(root, nullptr, nullptr, ans);
        return ans;
    }
};