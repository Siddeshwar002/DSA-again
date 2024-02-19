#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    void printBoundary(TreeNode *root)
    {
        if (root)
        {
            cout << root->val << " ";
            printLeftBoundary(root->left);
            printLeaves(root->left);
            printLeaves(root->right);
            printRightBoundary(root->right);
        }
    }

private:
    void printLeftBoundary(TreeNode *node)
    {
        // (!node->left && !node->right)
        // we are skipping the Leaf nodes
        if (!node || (!node->left && !node->right))
        {
            return;
        }

        // left elements are printed in normal order
        // top to bottom
        cout << node->val << " ";

        if (node->left)
        {
            printLeftBoundary(node->left);
        }
        else
        {
            printLeftBoundary(node->right);
        }
    }

    void printRightBoundary(TreeNode *node)
    {
        // (!node->left && !node->right)
        // we are skipping the Leaf nodes
        if (!node || (!node->left && !node->right))
        {
            return;
        }

        if (node->right)
        {
            printRightBoundary(node->right);
        }
        else
        {
            printRightBoundary(node->left);
        }

        // print has come after the recursion statement
        // right elements should be printed from the bottom
        cout << node->val << " ";
    }

    void printLeaves(TreeNode *node)
    {
        if (!node)
        {
            return;
        }

        // leaf condition
        if (!node->left && !node->right)
        {
            cout << node->val << " ";
            return;
        }

        printLeaves(node->left);
        printLeaves(node->right);
    }
};
