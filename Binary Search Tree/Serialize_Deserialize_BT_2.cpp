#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ! BFS Traversal and input and output stream

// ! No preorder and inOrder
// ! No recursions

// ! Time efficient CODE

string serialize(TreeNode *root)
{
    if (root == nullptr)
        return "null";

    std::queue<TreeNode *> q;
    q.push(root);
    std::stringstream ss;

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();

        if (node == nullptr)
        {
            ss << "null ";
            continue;
        }

        ss << std::to_string(node->val) << " ";
        q.push(node->left);
        q.push(node->right);
    }

    return ss.str();
}

// Decodes your encoded data to tree.
TreeNode *deserialize(std::string data)
{
    if (data == "null")
        return nullptr;

    std::istringstream ss(data);
    std::string nodeVal;
    ss >> nodeVal;

    TreeNode *root = new TreeNode(std::stoi(nodeVal));
    std::queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();

        if (!(ss >> nodeVal))
            break;
        if (nodeVal != "null")
        {
            curr->left = new TreeNode(std::stoi(nodeVal));
            q.push(curr->left);
        }

        if (!(ss >> nodeVal))
            break;
        if (nodeVal != "null")
        {
            curr->right = new TreeNode(std::stoi(nodeVal));
            q.push(curr->right);
        }
    }

    return root;
}
