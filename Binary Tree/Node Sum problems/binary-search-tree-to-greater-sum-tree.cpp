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
    int solve(TreeNode *root, int sum)
    {
        if (root == nullptr)
            return sum;

        int rightSum = solve(root->right, sum);
        sum = rightSum + root->val;
        root->val = sum;
        int leftSum = solve(root->left, sum);
        return leftSum;
    }

    TreeNode *bstToGst(TreeNode *root)
    {
        int sum = 0;
        int ans = solve(root, sum);
        return root;
    }
};