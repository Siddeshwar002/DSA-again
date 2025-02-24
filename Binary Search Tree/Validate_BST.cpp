#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left, *right;
};

struct TreeNode *newNode(int val)
{
    struct TreeNode *TreeNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    TreeNode->val = val;
    TreeNode->left = NULL;
    TreeNode->right = NULL;

    return (TreeNode);
}

bool isValidBST(TreeNode *root)
{
    return isValidBSTHelper(root, nullptr, nullptr);
}

// BST -> Min Node and Max Node approach

bool isValidBSTHelper(TreeNode *root, TreeNode *minNode, TreeNode *maxNode)
{
    if (!root)
        return true;

    if ((minNode && root->val <= minNode->val) || (maxNode && root->val >= maxNode->val))
        return false;

    return isValidBSTHelper(root->left, minNode, root) && isValidBSTHelper(root->right, root, maxNode);
}