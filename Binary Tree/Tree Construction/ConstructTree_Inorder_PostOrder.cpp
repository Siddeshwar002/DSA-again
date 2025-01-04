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
    TreeNode *constructTree(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd, unordered_map<int, int> &mp)
    {
        if (postStart > postEnd || inStart > inEnd)
            return nullptr;

        TreeNode *root = new TreeNode(postorder[postEnd]);
        int elem = mp[root->val];
        int nElem = elem - inStart;

        root->left = constructTree(inorder, inStart, elem - 1, postorder, postStart, postStart + nElem - 1, mp);
        root->right = constructTree(inorder, elem + 1, inEnd, postorder, postStart + nElem, postEnd - 1, mp);

        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int inStart = 0, inEnd = inorder.size() - 1;
        int postStart = 0, postEnd = postorder.size() - 1;

        unordered_map<int, int> mp;
        for (int i = 0; i <= inEnd; i++)
        {
            mp[inorder[i]] = i;
        }

        return constructTree(inorder, inStart, inEnd, postorder, postStart, postEnd, mp);
    }
};