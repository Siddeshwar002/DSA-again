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

class Solution
{
public:
    bool isEvenOddTree(TreeNode *root)
    {
        queue<TreeNode *> q;
        int level = -1;
        q.push(root);
        int ans = true;
        while (!q.empty())
        {

            int size = q.size();
            level++;
            vector<int> vec;

            for (int i = 0; i < size; i++)
            {
                TreeNode *cur = q.front();
                q.pop();

                vec.push_back(cur->val);

                if (cur->left != nullptr)
                    q.push(cur->left);

                if (cur->right != nullptr)
                    q.push(cur->right);
            }

            for (int i = 1; i < vec.size(); i++)
            {
                if ((level % 2 == 0 && (vec[i - 1] >= vec[i]) || vec[i - 1] % 2 != 1 || vec[i] % 2 != 1) ||

                    (level % 2 == 1 && (vec[i - 1] <= vec[i]) || vec[i - 1] % 2 != 0 || vec[i] % 2 != 0))
                {
                    ans = false;
                    break;
                }
            }

            if (vec.size() >= 1 && (level % 2 == 0 && vec[0] % 2 != 1) || (level % 2 == 1 && vec[0] % 2 != 0))
                ans = false;

            if (!ans)
                break;
        }
        return ans;
    }
};