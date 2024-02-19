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
    void solve(TreeNode *root, int minVal, int maxVal, int &ans)
    {
        if (root == nullptr)
            return;

        minVal = min(minVal, root->val);
        maxVal = max(maxVal, root->val);

        ans = max(ans, abs(maxVal - root->val) > abs(minVal - root->val) ? abs(maxVal - root->val) : abs(minVal - root->val));
        solve(root->left, minVal, maxVal, ans);
        solve(root->right, minVal, maxVal, ans);

        return;
    }
    int maxAncestorDiff(TreeNode *root)
    {
        int ans = 0;
        solve(root, INT_MAX, INT_MIN, ans);
        return ans;
    }
};