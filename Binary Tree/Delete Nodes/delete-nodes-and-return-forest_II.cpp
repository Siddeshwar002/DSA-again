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

class Solution
{
public:
    TreeNode *solve(TreeNode *root, const unordered_set<int> &to_delete, vector<TreeNode *> &forest)
    {
        if (!root)
            return nullptr;

        // First traverse the tree
        root->left = solve(root->left, to_delete, forest);
        root->right = solve(root->right, to_delete, forest);

        // then go for deletion
        // this makes sure that when you delete the current node
        // there are no nodes left under this node which have to be deleted
        if (to_delete.count(root->val))
        {
            if (root->left)
                forest.push_back(root->left);
            if (root->right)
                forest.push_back(root->right);
            return nullptr;
        }

        return root;
    }

    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
        vector<TreeNode *> forest;

        // a speacial case to check for the root node
        if (!to_delete_set.count(root->val))
            forest.push_back(root);

        solve(root, to_delete_set, forest);
        return forest;
    }
};
