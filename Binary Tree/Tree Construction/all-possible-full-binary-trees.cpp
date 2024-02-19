#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Recursive solution :
// accepted

class Solution
{
public:
    vector<TreeNode *> allPossibleFBT(int n)
    {
        // Base case: if n is even, no possible full binary trees
        if (n % 2 == 0)
            return {};
        // Base case: if n is 1, only one possible full binary tree with a single node
        if (n == 1)
            return {new TreeNode(0)};

        vector<TreeNode *> result;

        // For each possible number of nodes in the left subtree
        for (int leftNodes = 1; leftNodes < n; leftNodes += 2)
        {

            vector<TreeNode *> leftSubtrees = allPossibleFBT(leftNodes);
            vector<TreeNode *> rightSubtrees = allPossibleFBT(n - 1 - leftNodes);

            // Construct all combinations of left and right subtrees
            for (auto &leftSubtree : leftSubtrees)
            {
                for (auto &rightSubtree : rightSubtrees)
                {
                    TreeNode *root = new TreeNode(0);
                    root->left = leftSubtree;
                    root->right = rightSubtree;
                    result.push_back(root);
                }
            }
        }

        return result;
    }
};

// Memoization code
// Accepted

class Solution
{
public:
    vector<TreeNode *> solve(int n, vector<vector<TreeNode *>> &dp)
    {
        if (n % 2 == 0)
            return {};
        if (n == 1)
            return dp[n] = {new TreeNode(0)};

        if (!dp[n].empty())
            return dp[n];

        vector<TreeNode *> result;

        for (int i = 1; i < n; i += 2)
        {

            vector<TreeNode *> leftSubtrees = solve(i, dp);
            vector<TreeNode *> rightSubtrees = solve(n - 1 - i, dp);

            for (auto leftSubtree : leftSubtrees)
            {
                for (auto rightSubtree : rightSubtrees)
                {
                    TreeNode *root = new TreeNode(0);
                    root->left = leftSubtree;
                    root->right = rightSubtree;
                    result.push_back(root);
                }
            }
        }
        return dp[n] = result;
    }

    vector<TreeNode *> allPossibleFBT(int n)
    {
        vector<vector<TreeNode *>> dp(n + 1);
        return solve(n, dp);
    }
};

// Tabulation
// Try converting the above code into Tabulation