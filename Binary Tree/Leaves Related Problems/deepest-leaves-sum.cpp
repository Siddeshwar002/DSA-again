#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    void solve(TreeNode *root, int depth, int &maxDepth, int &ans)
    {
        if (root->right == nullptr && root->left == nullptr)
        {
            if (depth > maxDepth)
            {
                maxDepth = depth;
                ans = 0;
                ans += root->val;
            }
            else if (depth == maxDepth)
                ans += root->val;

            return;
        }

        if (root->left)
            solve(root->left, depth + 1, maxDepth, ans);
        if (root->right)
            solve(root->right, depth + 1, maxDepth, ans);

        return;
    }

    int deepestLeavesSum(TreeNode *root)
    {
        int ans = 0;
        int maxDepth = INT_MIN;
        solve(root, 0, maxDepth, ans);
        return ans;
    }
};