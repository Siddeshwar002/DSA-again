#include <bits/stdc++.h>
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
    vector<int> LargeBST(TreeNode *root, int &maxAns)
    {
        if (root == nullptr)
            return {0, INT_MIN, INT_MAX};

        vector<int> left = LargeBST(root->left, maxAns);
        vector<int> right = LargeBST(root->right, maxAns);

        vector<int> cur(3);

        if (left[1] < root->val && root->val < right[2])
        {
            cur[0] = left[0] + right[0] + root->val;
            cur[1] = max(root->val, right[1]);
            cur[2] = min(left[2], root->val);

            maxAns = max(maxAns, cur[0]);
            return cur;
        }
        else
        {
            cur[0] = max(left[0], right[0]);
            cur[1] = INT_MAX;
            cur[2] = INT_MIN;

            maxAns = max(maxAns, cur[0]);
            return cur;
        }
    }
    int maxSumBST(TreeNode *root)
    {
        int maxAns = 0;
        vector<int> ans = LargeBST(root, maxAns);
        return maxAns;
    }
};