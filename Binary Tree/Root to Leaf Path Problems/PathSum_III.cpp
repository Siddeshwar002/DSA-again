#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// function to convert array to tree
// debugging purpose
TreeNode *arrayToTree(const vector<int> &nums)
{
    if (nums.empty())
        return nullptr;

    TreeNode *root = new TreeNode(nums[0]);
    queue<TreeNode *> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nums.size())
    {
        TreeNode *current = q.front();
        q.pop();

        // Construct left child
        if (nums[i] != INT_MIN)
        {
            current->left = new TreeNode(nums[i]);
            q.push(current->left);
        }
        i++;

        // Construct right child
        if (i < nums.size() && nums[i] != INT_MIN)
        {
            current->right = new TreeNode(nums[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

// $ ******************************************************************************************************************
// Accepted
class Solution
{
public:
    int pathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
            return 0;

        return dfs(root, (long long)targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }

    int dfs(TreeNode *node, long long targetSum)
    {
        if (node == nullptr)
            return 0;

        int count = 0;
        if (node->val == targetSum)
            count++;

        count += dfs(node->left, targetSum - node->val);
        count += dfs(node->right, targetSum - node->val);

        return count;
    }
};

// $ ******************************************************************************************************************
// wrong Approach

class Solution1
{
public:
    void solve(TreeNode *root, int targetSum, int Sum, int &ans)
    {
        if (root == nullptr)
            return;

        Sum += root->val;
        if (Sum == targetSum)
            ans += 1;

        solve(root->left, targetSum, Sum, ans);
        solve(root->right, targetSum, Sum, ans);

        Sum = 0;

        solve(root->left, targetSum, Sum, ans);
        solve(root->right, targetSum, Sum, ans);

        return;
    }

    int pathSum(TreeNode *root, int targetSum)
    {
        int ans = 0;
        solve(root, targetSum, 0, ans);
        return ans;
    }
};

int main()
{
    vector<int> nums = {1, INT_MIN, 2, INT_MIN, 3, INT_MIN, 4, INT_MIN, 5};
    TreeNode *root = arrayToTree(nums);
    Solution s;
    s.pathSum(root, 3);
}