#include <iostream>
#include <algorithm>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// maxHeight is same as depth
int maxHeight(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int leftHeight = maxHeight(root->left);
    int rightHeight = maxHeight(root->right);

    return 1 + std::max(leftHeight, rightHeight);
}