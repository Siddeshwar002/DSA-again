#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Recursive code
// Accepted

class Solution
{
public:
    vector<TreeNode *> solve(int start, int end)
    {
        if (start > end)
            return {nullptr};

        vector<TreeNode *> result;

        for (int i = start; i <= end; i++)
        {
            TreeNode *root = new TreeNode(i);
            vector<TreeNode *> leftSubtrees = solve(start, i - 1);
            vector<TreeNode *> rightSubtrees = solve(i + 1, end);

            for (auto leftTree : leftSubtrees)
            {
                for (auto rightTree : rightSubtrees)
                {
                    // creating a new node and adding that to the vector
                    TreeNode *root = new TreeNode(i);
                    root->left = leftTree;
                    root->right = rightTree;
                    result.push_back(root);
                }
            }
        }
        return result;
    }
    vector<TreeNode *> generateTrees(int n)
    {
        return solve(1, n);
    }
};

// Memoization code
// Accepted

class Solution
{
public:
    vector<vector<vector<TreeNode *>>> memo;

    vector<TreeNode *> solve(int start, int end)
    {
        if (start > end)
            return {nullptr};

        if (!memo[start][end].empty())
            return memo[start][end];

        vector<TreeNode *> result;

        for (int i = start; i <= end; i++)
        {
            vector<TreeNode *> leftSubtrees = solve(start, i - 1);
            vector<TreeNode *> rightSubtrees = solve(i + 1, end);

            for (auto leftTree : leftSubtrees)
            {
                for (auto rightTree : rightSubtrees)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = leftTree;
                    root->right = rightTree;
                    result.push_back(root);
                }
            }
        }

        memo[start][end] = result;
        return result;
    }

    vector<TreeNode *> generateTrees(int n)
    {
        memo.assign(n + 1, vector<vector<TreeNode *>>(n + 1));
        return solve(1, n);
    }
};

// Try making a tabulation code also
// code here ...
// My code pending ...

// Not my Tabulation :
// Accepted

class Solution
{
public:
    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
            return {};

        // Create a 2D vector to store results for subproblems
        vector<vector<vector<TreeNode *>>> dp(n + 2, vector<vector<TreeNode *>>(n + 2));

        // Base case: for each length 1 subtree (i.e., single node trees)
        for (int i = 1; i <= n; ++i)
        {
            TreeNode *root = new TreeNode(i);
            dp[i][i] = {root};
        }

        // Iterate over different lengths of subtrees
        for (int len = 2; len <= n; ++len)
        {
            // Iterate over all possible starting indices of subtrees
            for (int start = 1; start <= n - len + 1; ++start)
            {
                int end = start + len - 1;

                // Generate all possible trees for the current length and range
                for (int i = start; i <= end; ++i)
                {
                    vector<TreeNode *> leftSubtrees = (i == start) ? vector<TreeNode *>{nullptr} : dp[start][i - 1];
                    vector<TreeNode *> rightSubtrees = (i == end) ? vector<TreeNode *>{nullptr} : dp[i + 1][end];

                    // Construct trees combining left and right subtrees
                    for (TreeNode *left : leftSubtrees)
                    {
                        for (TreeNode *right : rightSubtrees)
                        {
                            TreeNode *root = new TreeNode(i);
                            root->left = left;
                            root->right = right;
                            dp[start][end].push_back(root);
                        }
                    }
                }
            }
        }

        return dp[1][n];
    }
};

int main()
{
    Solution s;
    s.generateTrees(3);
}
