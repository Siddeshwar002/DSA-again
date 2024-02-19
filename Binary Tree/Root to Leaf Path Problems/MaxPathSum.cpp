
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

int findMaxPathSum(TreeNode *root, int &maxi)
{
    if (root == NULL)
        return 0;

    // ! This handles the negative value nodes
    // * max(0 , leftRetured Value);
    // * max(0 , RightRetured Value);

    int leftMaxPath = max(0, findMaxPathSum(root->left, maxi));
    int rightMaxPath = max(0, findMaxPathSum(root->right, maxi));
    int val = root->val;
    maxi = max(maxi, (leftMaxPath + rightMaxPath) + val);
    return max(leftMaxPath, rightMaxPath) + val;
}

int maxPathSum(TreeNode *root)
{
    int maxi = INT_MIN;
    findMaxPathSum(root, maxi);
    return maxi;
}

int main()
{
    struct TreeNode *root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(8);

    root->left->left = newNode(6);
    root->left->right = newNode(7);

    root->right->left = newNode(-9);
    root->right->right = newNode(1);

    root->left->left->left = newNode(-1);
    root->left->left->right = newNode(-1);
    maxPathSum(root);
}