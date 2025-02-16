// #include <bits/stdc++.h>
#include "../../stdc++.h"
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

    // Normal DFS code
    void dfs(TreeNode *root, int k, vector<int> &ans)
    {
        if (root == nullptr || k < 0)
            return;
        
        // Answer reached
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

        // This function collects all the nodes above the target node.
        // It keeps the direction they are present : this helps us tell on which dorection to move next time.
        // This direction is usually the other side from where the target node was existing.
        // This also keeps track of how much distance to move in this direction.
        solve(root, target, h, Nodes);

        vector<int> ans;

        // DFS from all the Parent nodes (all nodes which are above Target) of Target to find the answer
        for (auto Node : Nodes)
        {
            if (Node.second.second == 0)
                ans.push_back(Node.first->val);
            else
            {  
                // target was found on left
                if (Node.second.first == 1)
                    // so move right
                    dfs(Node.first->right, Node.second.second - 1, ans);
                // target was found on right 
                else if (Node.second.first == 2)
                    // so move left
                    dfs(Node.first->left, Node.second.second - 1, ans);
            }
        }

        // DFS from the Target Node to Down
        dfs(target, k, ans);

        return ans;
    }
};