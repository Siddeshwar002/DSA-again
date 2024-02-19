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

// Good intuition
// Good code
// BUT as due to the incomplete looping of the ans array
// it fails
// refer the other file for correct code

TreeNode *createBinaryTree(const vector<int> &arr)
{
    if (arr.empty())
        return nullptr;

    TreeNode *root = new TreeNode(arr[0]);
    queue<TreeNode *> q;
    q.push(root);

    for (int i = 1; i < arr.size(); ++i)
    {
        TreeNode *parent = q.front();
        q.pop();

        if (arr[i] != -1)
        {
            parent->left = new TreeNode(arr[i]);
            q.push(parent->left);
        }

        if (i + 1 < arr.size() && arr[i + 1] != -1)
        {
            parent->right = new TreeNode(arr[i + 1]);
            q.push(parent->right);
        }

        ++i;
    }

    return root;
}

class Solution
{
private:
    vector<TreeNode *> ans;

public:
    void solve(TreeNode *root, vector<int> &to_delete, TreeNode *parent, bool left)
    {

        if (!root)
            return;

        if (find(to_delete.begin(), to_delete.end(), root->val) != to_delete.end())
        {
            auto it = find(to_delete.begin(), to_delete.end(), root->val);
            to_delete.erase(it);

            if (root->left != nullptr)
                ans.push_back(root->left);
            if (root->right != nullptr)
                ans.push_back(root->right);

            if (left)
                parent->left = nullptr;
            else
                parent->right = nullptr;

            auto ot = find(ans.begin(), ans.end(), root);
            if (ot != ans.end())
                ans.erase(ot);

            return;
        }

        solve(root->left, to_delete, root, true);
        solve(root->right, to_delete, root, false);
    }

    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        ans.push_back(root);

        for (auto root : ans)
        {
            if (to_delete.size() == 0)
                break;
            solve(root, to_delete, root, true);
        }

        return ans;
    }
};

int main()
{
    vector<int> vec = {1, 2, -1, 4, 3};
    TreeNode *root = createBinaryTree(vec);
    vector<int> del = {2, 3};
    Solution s;
    vector<TreeNode *> ans = s.delNodes(root, del);
}