
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// struct TreeNode *newNode(int val)
// {
//     struct TreeNode *TreeNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
//     TreeNode->val = val;
//     TreeNode->left = NULL;
//     TreeNode->right = NULL;

//     return (TreeNode);
// }

TreeNode *ConstructTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> &mp)
{

    if (preStart > preEnd or inStart > inEnd)
        return NULL;

    TreeNode *root = new TreeNode(preorder[preStart]);
    int ele = mp[root->val];
    int Nele = ele - inStart;

    root->left = ConstructTree(preorder, preStart + 1, preStart + Nele, inorder, inStart, ele - 1, mp);

    root->right = ConstructTree(preorder, preStart + Nele + 1, preEnd, inorder, ele + 1, inEnd, mp);

    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i;
    }

    return ConstructTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
}