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
    TreeNode *solve(vector<int> &preorder, vector<int> &postorder, int preStart, int preEnd, int postStart, int postEnd, map<int, int> &preMap, map<int, int> &postMap)
    {
        if (preEnd < preStart || postEnd < postStart)
            return nullptr;

        TreeNode *root = new TreeNode(preorder[preStart]);
        if (preStart == preEnd)
        {
            return root;
        }
        int p2 = postMap[preorder[preStart + 1]];
        int p1 = preMap[postorder[postEnd - 1]];

        root->left = solve(preorder, postorder, preStart + 1, p1 - 1, postStart, p2, preMap, postMap);
        root->right = solve(preorder, postorder, p1, preEnd, p2 + 1, postEnd - 1, preMap, postMap);

        return root;
    }

    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        map<int, int> preMap, postMap;
        int i = 0;
        int n = preorder.size();

        for (auto e : preorder)
            preMap[e] = i++;

        i = 0;

        for (auto e : postorder)
            postMap[e] = i++;

        return solve(preorder, postorder, 0, n - 1, 0, n - 1, preMap, postMap);
    }
};

int main()
{
    Solution s;
    vector<int> preorder = {1, 2};
    vector<int> postorder = {2, 1};
    s.constructFromPrePost(preorder, postorder);
}