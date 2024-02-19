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
    int solve(TreeNode *root, unordered_map<int, int> mp)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            mp[root->val]++;
            int cnt = 0;
            for (auto ele : mp)
            {
                if (ele.second % 2 == 1)
                    cnt++;
            }
            if (cnt > 1)
                return 0;
            return 1;
        }

        mp[root->val]++;
        int left = 0, right = 0;
        if (root->left != nullptr)
            left = solve(root->left, mp);
        if (root->right != nullptr)
            right = solve(root->right, mp);
        return left + right;
    }

    int pseudoPalindromicPaths(TreeNode *root)
    {
        unordered_map<int, int> mp;
        return solve(root, mp);
    }
};