#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    void dfs(TreeNode *root, int maxNode, int &cnt)
    {
        if (!root)
            return;

        if (root->val >= maxNode)
            cnt++;
        maxNode = max(maxNode, root->val);

        dfs(root->left, maxNode, cnt);
        dfs(root->right, maxNode, cnt);
        return;
    }
    int goodNodes(TreeNode *root)
    {
        int cnt = 0;
        dfs(root, root->val, cnt);
        return cnt;
    }
};