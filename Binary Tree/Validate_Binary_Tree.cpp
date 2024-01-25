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

bool isValidBSTHelper(TreeNode *root, TreeNode *minNode, TreeNode *maxNode)
{
    if (!root)
    {
        return true; // Empty tree is a valid BST
    }

    if ((minNode && root->val <= minNode->val) || (maxNode && root->val >= maxNode->val))
    {
        return false; // Node value violates BST property
    }

    // Recursively check left subtree with updated maximum value as current node
    // Recursively check right subtree with updated minimum value as current node
    return isValidBSTHelper(root->left, minNode, root) && isValidBSTHelper(root->right, root, maxNode);
}