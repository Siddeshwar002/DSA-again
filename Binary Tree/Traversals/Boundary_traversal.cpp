#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Apprach 1 : 
// Recursive Approach : 
class Solution
{
public:
    void printBoundary(TreeNode *root)
    {
        if (root)
        {   
            // Print the Root 
            cout << root->val << " ";

            // if(!root->left && !root->right)return;
            
            // Print left boundary
            printLeftBoundary(root->left);
            
            // Print left leaves
            printLeaves(root->left);
            
            // Print left leaves
            printLeaves(root->right);

            // Print Right Boundary
            printRightBoundary(root->right);
        }
    }

private:
    void printLeftBoundary(TreeNode *node)
    {
        // Skip the Leaf nodes
        if (!node || (!node->left && !node->right))
            return;

        cout << node->val << " ";

        if (node->left)
            printLeftBoundary(node->left);
        else
            printLeftBoundary(node->right);
    }

    void printRightBoundary(TreeNode *node)
    {
        // Skip the Leaf nodes
        if (!node || (!node->left && !node->right))
            return;

        if (node->right)
            printRightBoundary(node->right);
        else
            printRightBoundary(node->left);

        // print has come after the recursion statement
        // right elements should be printed from the bottom
        cout << node->val << " ";
    }

    void printLeaves(TreeNode *node)
    {
        if (!node)
            return;

        // leaf condition
        if (!node->left && !node->right)
        {
            cout << node->val << " ";
            return;
        }

        printLeaves(node->left);
        printLeaves(node->right);
    }
};

// **************************************************************************************************

// Appraoach 2 : 
// Iterattive approach

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isLeaf(Node* root) {
        return !root->left && !root->right;
    }

    void addLeftBoundary(Node* root, vector<int>& res) {
        Node* curr = root->left;
        while (curr) {
            if (!isLeaf(curr)) 
                res.push_back(curr->data);

            if (curr->left) 
                curr = curr->left;
            else 
                curr = curr->right;
        }
    }

    void addRightBoundary(Node* root, vector<int>& res) {
        Node* curr = root->right;
        vector<int> temp;
        
        while (curr) {
            if (!isLeaf(curr)) 
                temp.push_back(curr->data);
            if (curr->right) 
                curr = curr->right;
            else 
                curr = curr->left;
        }

        // reversing the right nodes
        // as we are traversing from the bottom
        for (int i = temp.size() - 1; i >= 0; --i) {
            res.push_back(temp[i]);
        }
    }

    void addLeaves(Node* root, vector<int>& res) {
        if (isLeaf(root)) {
            res.push_back(root->data);
            return;
        }

        if (root->left) 
            addLeaves(root->left, res);
        
        if (root->right) 
            addLeaves(root->right, res);
        
    }

    vector<int> printBoundary(Node* root) {
        vector<int> res;
        
        if (!root) 
            return res;
        
        // add the first root
        if (!isLeaf(root)) 
            res.push_back(root->data);

        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);

        return res;
    }
};
