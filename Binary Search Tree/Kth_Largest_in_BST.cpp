#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

int KthSmallestHelper(Node *root, int k, int RightEle, int &ans)
{
    if (!root)
        return 0;
    // if (RightEle + 1 > k)
    //     return 0;

    int rh = KthSmallestHelper(root->right, k, RightEle, ans);
    RightEle += rh;
    int lh = KthSmallestHelper(root->left, k, RightEle + 1, ans);

    if (RightEle + 1 == k)
        ans = root->data;

    return lh + rh + 1;
}

int kthSmallest(Node *root, int k)
{
    int ans = 0;
    KthSmallestHelper(root, k, 0, ans);
    return ans;
}

int main()
{
    int k = 4;
    Node *root = new Node(5);

    root->left = new Node(3);
    root->right = new Node(6);

    root->left->left = new Node(2);
    root->left->right = new Node(4);

    root->left->left->left = new Node(1);

    cout << "Ans : " << kthSmallest(root, k);
}