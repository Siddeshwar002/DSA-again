#include "../stdc++.h"
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int checkisBalanced(TreeNode *root)
    {
        if (!root)
            return 0;

        int left = checkisBalanced(root->left);
        int right = checkisBalanced(root->right);

        if (left == INT_MAX || right == INT_MAX)
            return INT_MAX;

        if (abs(left - right) <= 1)
            return max(left, right) + 1;
        else
            return INT_MAX;
    }

    bool isBalanced(TreeNode *root)
    {
        if (checkisBalanced(root) == INT_MAX)
            return false;

        return true;
    }
};