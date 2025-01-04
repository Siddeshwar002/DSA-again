// #include <bits/stdc++.h>
#include "../../stdc++.h"

using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// HARD
// using STACK to construct a tree

class Solution
{
public:
    TreeNode *recoverFromPreorder(string traversal)
    {
        int i = 0;
        int n = traversal.size();
        stack<TreeNode *> st;

        while (i < n)
        {
            int level = 0;
            while (i < n && traversal[i] == '-')
            {
                ++i;
                ++level;
            }

            int val = 0;
            while (i < n && isdigit(traversal[i]))
            {
                val = val * 10 + (traversal[i] - '0');
                i++;
            }

            TreeNode *node = new TreeNode(val);

            while (st.size() > level)
                st.pop();

            if (!st.empty())
            {
                TreeNode *parent = st.top();
                if (parent->left == nullptr)
                    parent->left = node;
                else if (parent->right == nullptr)
                    parent->right = node;
            }

            st.push(node);
        }

        while (st.size() > 1)
            st.pop();

        return st.top();
    }
};