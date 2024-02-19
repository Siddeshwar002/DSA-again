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
    vector<int> solve(TreeNode *root, int distance, int &cnt)
    {
        if (!root)
            return {};

        if (!root->left and !root->right)
            return {0};

        vector<int> leftDistance = solve(root->left, distance, cnt);
        vector<int> rightDistance = solve(root->right, distance, cnt);

        vector<int> curDistance;

        for (auto leftNodes : leftDistance)
        {
            for (auto rightNodes : rightDistance)
            {
                if (leftNodes + rightNodes + 2 <= distance)
                    cnt++;
            }
        }

        for (auto leftNodes : leftDistance)
        {
            if (leftNodes + 1 < distance)
                curDistance.push_back(leftNodes + 1);
        }

        for (auto rightNodes : rightDistance)
        {
            if (rightNodes + 1 < distance)
                curDistance.push_back(rightNodes + 1);
        }

        return curDistance;
    }

    int countPairs(TreeNode *root, int distance)
    {
        int cnt = 0;
        solve(root, distance, cnt);
        return cnt;
    }
};