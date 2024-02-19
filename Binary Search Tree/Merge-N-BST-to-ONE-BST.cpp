#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Approach 1
// 428 / 475 testcases passed

class CreateBST
{
public:
    TreeNode *buildBSTFromInorder(const vector<int> &inorder, int &index)
    {
        if (index >= inorder.size() || inorder[index] == -1)
            return nullptr;

        TreeNode *root = new TreeNode(inorder[index]);
        ++index;

        root->left = buildBSTFromInorder(inorder, index);
        ++index;
        root->right = buildBSTFromInorder(inorder, index);

        return root;
    }
};

class Solution
{
public:
    TreeNode *mergeBST(TreeNode *root1, TreeNode *root2, int minNode, int maxNode, bool &mergeSuccessful, map<int, multiset<int>> &mp)
    {
        if (root1 == nullptr)
            return root1;

        if (root2->val < root1->val)
        {
            root1->left = mergeBST(root1->left, root2, minNode, root1->val, mergeSuccessful, mp);
        }
        else if (root1->val < root2->val)
        {
            root1->right = mergeBST(root1->right, root2, root1->val, maxNode, mergeSuccessful, mp);
        }
        else if (root1->val == root2->val)
        {
            if ((root2->left != nullptr && root2->left->val <= minNode) || root2->right != nullptr && root2->right->val >= maxNode)
                return root1;
            else
            {
                mergeSuccessful = true;
                return root2;
            }
        }
        return root1;
    }

    TreeNode *canMerge(vector<TreeNode *> &trees)
    {
        if (trees.empty())
            return nullptr;
        if (trees.size() == 1)
            return trees[0];

        map<int, multiset<int>> mp;

        // Populate multiset with leaf nodes
        for (auto tree : trees)
        {
            if (tree->left != nullptr)
                mp[tree->val].insert(tree->left->val);
            if (tree->right != nullptr)
                mp[tree->val].insert(tree->right->val);
        }

        TreeNode *root1 = trees[0];
        trees.erase(trees.begin());

        while (!trees.empty())
        {
            TreeNode *root2 = nullptr;

            for (auto tree : trees)
            {
                root2 = nullptr;
                bool mergeSuccessful = false;
                int val1 = root1->val;
                int val2 = tree->val;

                // Check if merge is possible
                if (mp[val1].find(val2) != mp[val1].end())
                {
                    mergeBST(root1, tree, INT_MIN, INT_MAX, mergeSuccessful, mp);
                }
                else if (!mergeSuccessful && mp[val2].find(val1) != mp[val2].end())
                {
                    // swap(root1, tree);
                    mergeBST(tree, root1, INT_MIN, INT_MAX, mergeSuccessful, mp);
                    root1 = tree;
                }

                // Handle successful merge
                if (mergeSuccessful)
                {
                    // Update multiset and remove merged node
                    if (tree->left != nullptr)
                        mp[root1->val].insert(tree->left->val);
                    if (tree->right != nullptr)
                        mp[root1->val].insert(tree->right->val);
                    mp[root1->val].erase(tree->val);

                    // Update root2 and remove from vector
                    root2 = tree;
                    // trees.erase(remove(trees.begin(), trees.end(), tree), trees.end());
                    auto it = find(trees.begin(), trees.end(), tree);
                    if (it != trees.end())
                    {
                        trees.erase(it);
                    }
                }
            }

            // Check if a valid root2 is found
            if (root2 == nullptr)
                return nullptr;
        }

        return root1;
    }
};

int main()
{
    vector<vector<int>> vectors = {{5, 1}, {1, -1, 4}, {4, 2}, {2, -1, 3}};
    // CreateBST BST;
    vector<TreeNode *> roots;

    TreeNode *root1 = new TreeNode(5);
    root1->left = new TreeNode(1);

    TreeNode *root2 = new TreeNode(1);
    root2->right = new TreeNode(4);

    TreeNode *root3 = new TreeNode(4);
    root3->left = new TreeNode(2);

    TreeNode *root4 = new TreeNode(2);
    root4->right = new TreeNode(3);

    roots.push_back(root1);
    roots.push_back(root2);
    roots.push_back(root3);
    roots.push_back(root4);

    // for (auto vec : vectors)
    // {
    //     int idx = 0;
    //     TreeNode *cur = BST.buildBSTFromInorder(vec, idx);
    //     roots.push_back(cur);
    // }

    for (auto root : roots)
        cout << root->val << " ";

    Solution s;
    cout<<s.canMerge(roots);
    return 0;
}