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

// Approch 1
// Self
// accepted

class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
            return root;

        if (key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val)
        {
            root->right = deleteNode(root->right, key);
        }
        else if (root->val == key)
        {

            if (root->right == nullptr)
                return root->left;
            if (root->left == nullptr)
                return root->right;

            TreeNode *left = root->left;
            TreeNode *left_2 = root->left;
            TreeNode *right = root->right;

            while (left_2->right != nullptr)
                left_2 = left_2->right;

            left_2->right = right->left;
            right->left = left;
            return right;
        }
        return root;
    }
};

// Approach 2 :
// a more efficient code

// bringing the successor to the top

class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return nullptr;

        if (key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            if (!root->left)
            {
                TreeNode *rightChild = root->right;
                delete root;
                return rightChild;
            }
            else if (!root->right)
            {
                TreeNode *leftChild = root->left;
                delete root;
                return leftChild;
            }
            else
            {
                // bring the successor on the top
                TreeNode *successor = root->right;
                while (successor->left)
                {
                    successor = successor->left;
                }
                root->val = successor->val;
                root->right = deleteNode(root->right, successor->val);
            }
        }
        return root;
    }
};
