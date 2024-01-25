#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void preOrder(TreeNode *root, string &preorder)
{
    if (!root)
        return;

    preorder.push_back('0' + root->val);
    preOrder(root->left, preorder);
    preOrder(root->right, preorder);
}

void inOrder(TreeNode *root, string &inorder)
{
    if (!root)
        return;

    inOrder(root->left, inorder);
    inorder.push_back('0' + root->val);
    inOrder(root->right, inorder);
}

string serialize(TreeNode *root)
{
    string preorder = "";
    preOrder(root, preorder);

    string inorder = "";
    inOrder(root, inorder);

    // cout<<preorder<<endl;
    return preorder + inorder;
}

TreeNode *ConstructTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> &mp)
{

    if (preStart > preEnd or inStart > inEnd)
        return NULL;

    TreeNode *root = new TreeNode(preorder[preStart]);
    int ele = mp[root->val];
    int Nele = ele - inStart;

    root->left = ConstructTree(preorder, preStart + 1, preStart + Nele, inorder, inStart, ele - 1, mp);

    root->right = ConstructTree(preorder, preStart + Nele + 1, preEnd, inorder, ele + 1, inEnd, mp);

    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i;
    }

    return ConstructTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
}

TreeNode *deserialize(string data)
{
    vector<int> preOrder;
    vector<int> InOrder;

    for (int i = 0; i < data.size(); i++)
    {
      if(isdigit(data[i] - 48)){
          if (i < data.size() / 2)
              preOrder.push_back(data[i] - 48);
          else
              InOrder.push_back(data[i] - 48);
      }
    }

    return buildTree(preOrder , InOrder);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    // Serialize the binary tree
    serialize(root);
    deserialize("123465");
}