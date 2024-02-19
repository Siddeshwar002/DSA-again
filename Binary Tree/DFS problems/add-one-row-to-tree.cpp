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
    TreeNode *solveDFS(TreeNode *root, int val, int depth, bool left)
    {
        if (!root && depth != 1)
            return root;

        if (depth == 1)
        {
            TreeNode *newNode = new TreeNode(val);
            if (left)
                newNode->left = root;
            else
                newNode->right = root;

            return newNode;
        }

        root->left = solveDFS(root->left, val, depth - 1, true);
        root->right = solveDFS(root->right, val, depth - 1, false);

        return root;
    }

    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        return solveDFS(root, val, depth, true);
    }
};