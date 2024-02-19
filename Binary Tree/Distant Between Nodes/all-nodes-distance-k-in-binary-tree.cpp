#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// My Novel Approach
// Beats 100% of the Solutions

class Solution
{
public:
    // This function stores all the parent nodes above the target
    // their distance
    // and the next traversal direction
    bool solve(TreeNode *root, TreeNode *target, int &h, vector<pair<TreeNode *, pair<int, int>>> &Nodes)
    {
        if (root == nullptr)
            return 0;

        if (h < 0)
            return 0;

        if (root == target)
            return 1;

        bool left = solve(root->left, target, h, Nodes);
        bool right = solve(root->right, target, h, Nodes);

        if (left && h >= 0)
        {
            h--;
            Nodes.push_back({root, {1, h}});
        }
        else if (right && h >= 0)
        {
            h--;
            Nodes.push_back({root, {2, h}});
        }

        return (left || right);
    }

    // normal DFS
    void dfs(TreeNode *root, int k, vector<int> &ans)
    {
        if (root == nullptr || k < 0)
            return;

        if (k == 0)
        {
            ans.push_back(root->val);
            return;
        }

        dfs(root->left, k - 1, ans);
        dfs(root->right, k - 1, ans);

        return;
    }

    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        vector<pair<TreeNode *, pair<int, int>>> Nodes;
        int h = k;
        solve(root, target, h, Nodes);
        vector<int> ans;

        // DFS from all the Parent nodes  of Target to find the answer
        for (auto Node : Nodes)
        {
            if (Node.second.second == 0)
                ans.push_back(Node.first->val);
            else
            {
                if (Node.second.first == 1)
                    dfs(Node.first->right, Node.second.second - 1, ans);
                else if (Node.second.first == 2)
                    dfs(Node.first->left, Node.second.second - 1, ans);
            }
        }

        // DFS down from the Target Node
        dfs(target, k, ans);

        return ans;
    }
};