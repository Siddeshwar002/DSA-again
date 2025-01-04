// #include <bits/stdc++.h>
#include "../../stdc++.h"

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
    void solve(TreeNode *root, TreeNode *&prev, TreeNode *&first, TreeNode *&mid, TreeNode *&last)
    {
        if (!root)
            return;

        // Left
        solve(root->left, prev, first, mid, last);

        // Visited the node
        if (prev != nullptr && (root->val < prev->val))
        {
            if (first == nullptr)
            {
                first = prev;
                mid = root;
            }
            else
                last = root;
        }

        prev = root;

        // Right
        solve(root->right, prev, first, mid, last);

        return;
    }
    void recoverTree(TreeNode *root)
    {
        TreeNode *prev = new TreeNode(INT_MIN);
        TreeNode *first = nullptr;
        TreeNode *mid = nullptr;
        TreeNode *last = nullptr;

        solve(root, prev, first, mid, last);
        if (first && last)
            swap(first->val, last->val);
        else if (first && mid)
            swap(first->val, mid->val);

        return;
    }
};

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);
    Solution s;
    s.recoverTree(root);
}