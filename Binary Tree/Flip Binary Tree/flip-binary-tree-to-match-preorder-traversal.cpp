#include <bits/stdc++.h>
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
    vector<int> flipMatchVoyage(TreeNode *root, vector<int> &voyage)
    {
        vector<int> result;
        int idx = 0;
        if (preorderTraversal(root, voyage, idx, result))
            return result;
        else
            return {-1};
    }

private:
    bool preorderTraversal(TreeNode *node, vector<int> &voyage, int &idx, vector<int> &result)
    {
        if (!node)
            return true;

        // idx is getting incremented
        if (node->val != voyage[idx++])
            return false;

        // Handling nullptr case for leftChild
        if (node->left && node->left->val != voyage[idx])
        {
            result.push_back(node->val);
            // This is the catch
            swap(node->left, node->right);
        }
        return preorderTraversal(node->left, voyage, idx, result) &&
               preorderTraversal(node->right, voyage, idx, result);
    }
};
