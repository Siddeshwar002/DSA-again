#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int KthSmallestHelper(TreeNode *root, int k, int leftEle, int &ans)
{
    if (!root)
        return 0;
    // if (leftEle + 1 > k)
    //     return 0;

    int lh = KthSmallestHelper(root->left, k, leftEle, ans);
    leftEle += lh;
    int rh = KthSmallestHelper(root->right, k, leftEle + 1, ans);

    if (leftEle + 1 == k)
        ans = root->val;

    return lh + rh + 1;
}

int kthSmallest(TreeNode *root, int k)
{
    int ans = 0;
    KthSmallestHelper(root, k, 0, ans);
    return ans;
}

int main()
{
    int k = 4;
    TreeNode *root = new TreeNode(5);

    root->left = new TreeNode(3);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->left->left->left = new TreeNode(1);

    cout << "Ans : " << kthSmallest(root, k);
}