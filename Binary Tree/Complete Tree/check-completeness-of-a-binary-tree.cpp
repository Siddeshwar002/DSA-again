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
    bool isCompleteTree(TreeNode *root)
    {
        queue<TreeNode *> q;
        if (!root)
            return true;
        q.push(root);

        int hasNull = false;

        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();

            // If we've encountered a null node previously, at this particular level then
            // all the remaining nodes should also be null

            if (hasNull)
            {
                if (cur)
                    return false;
            }
            else
            {
                if (!cur)
                {
                    hasNull = true;
                }
                else
                {
                    q.push(cur->left);
                    q.push(cur->right);
                }
            }
        }
        return true;
    }
};