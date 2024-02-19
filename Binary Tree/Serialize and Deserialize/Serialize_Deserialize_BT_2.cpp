#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//  BFS Traversal and input and output stream

// Encodes tree to String
string serialize(TreeNode *root)
{
    if (root == nullptr)
        return "null";

    queue<TreeNode *> q;
    q.push(root);
    stringstream ss;

    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();

        if (node == nullptr)
        {
            ss << "null ";
            continue;
        }

        ss << to_string(node->val) << " ";

        // Don't check for these below conditions
        // because while decoding if you encounter a NULL value
        // it will skip insertion of node at that position

        // if (node->left != nullptr)
        q.push(node->left);

        // if (node->right != nullptr)
        q.push(node->right);
    }

    return ss.str();
}

// Decodes your encoded string to tree.
TreeNode *deserialize(string data)
{
    if (data == "null")
        return nullptr;

    istringstream ss(data);
    string nodeVal;

    // extracts the first node as string
    // '>>' -> word extracting operator
    ss >> nodeVal;

    // stoi -> string to integer conversion
    TreeNode *root = new TreeNode(stoi(nodeVal));
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();

        // extract the next node
        // also check if the string ends
        if (!(ss >> nodeVal))
            break;

        if (nodeVal != "null")
        {
            curr->left = new TreeNode(stoi(nodeVal));
            q.push(curr->left);
        }

        // extract the next node
        // also check if the string ends
        if (!(ss >> nodeVal))
            break;

        if (nodeVal != "null")
        {
            curr->right = new TreeNode(stoi(nodeVal));
            q.push(curr->right);
        }
    }

    return root;
}
