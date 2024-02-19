#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ! Recursive Approach
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if ((root->val > p->val) && (root->val > q->val))
    {
        return lowestCommonAncestor(root->left, p, q);
    }
    if ((root->val < p->val) && (root->val < q->val))
    {
        return lowestCommonAncestor(root->right, p, q);
    }
    return root;
}

// ! Iterative Approach
// This works becuase you are just going down in one diretction
// there is no coming back moving in the other direction
// you are sure that there is answer in the path where you are moving
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    TreeNode *cur = root;
    while (true)
    {
        if (p->val < cur->val && q->val < cur->val)
        {
            cur = cur->left;
        }
        else if (p->val > cur->val && q->val > cur->val)
        {
            cur = cur->right;
        }
        else
        {
            break;
        }
    }
    return cur;
}