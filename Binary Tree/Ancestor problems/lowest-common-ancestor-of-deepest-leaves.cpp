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
    int solve(TreeNode *root, int depth, int &maxDepth, TreeNode *&ans)
    {
        if (!root)
            return 0;

        int lh = solve(root->left, depth + 1, maxDepth, ans);
        int rh = solve(root->right, depth + 1, maxDepth, ans);

        if (lh == rh)
        {
            ans = (depth + lh >= maxDepth) ? root : ans;
            maxDepth = (depth + lh >= maxDepth) ? depth + lh : maxDepth;
        }
        return 1 + max(lh, rh);
    }

    TreeNode *lcaDeepestLeaves(TreeNode *root)
    {
        TreeNode *ans;
        int maxDepth = -1;

        int height = solve(root, 0, maxDepth, ans);
        return ans;
    }
};