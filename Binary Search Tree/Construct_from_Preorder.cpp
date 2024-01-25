#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// ! RECURSIVE code - Time consuming
// TODO : Scroll down for better approach 

TreeNode *constructTree(vector<int> preorder, int &i, TreeNode *minNode, TreeNode *maxNode)
{
    if (i >= preorder.size())
        return NULL;

    if ((minNode && minNode->val > preorder[i]) || (maxNode && maxNode->val < preorder[i]))
    {
        return NULL;
    }

    TreeNode *curr = new TreeNode(preorder[i]);
    i++;
    curr->left = constructTree(preorder, i, minNode, curr);
    curr->right = constructTree(preorder, i, curr, maxNode);
    return curr;
}

// ! BETTER SOLUTION
TreeNode *bstFromPreorder(vector<int> &preorder)
{
    if (preorder.size() == 0)
    { // If vector is empty, return NULL
        return NULL;
    }

    TreeNode *root = new TreeNode(preorder[0]); // Tree will start off with vector's first value;

    for (int i = 1; i < preorder.size(); i++)
    {                             // Traversing the vector
        bool done = false;        // Marker to indicate when the vector value has been added to the tree
        TreeNode *current = root; // Current is used to traverse the tree we're creating

        while (done == false)
        {
            if (preorder[i] < current->val)
            { // If the vector value is less than the current tree node's value
                if (current->left == NULL)
                { // Add the vector value to the tree if there is an available spot
                    current->left = new TreeNode(preorder[i]);
                    done = true; // Vector value has been added, therefore done = true and break out of while loop
                }
                else
                { // If there's no available spot, keep traversing our tree
                    current = current->left;
                }
            }
            else
            { // If vector value is greater than current tree node's value
                if (current->right == NULL)
                { // Add the vector value to tree if spot is available
                    current->right = new TreeNode(preorder[i]);
                    done = true; // Vector value added, therefore break out of while loop
                }
                else
                {
                    current = current->right; // No spot available, keep traversing tree
                }
            }
        }
    }

    return root;
}

int main()
{
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    int i = 0;
    constructTree(preorder, i, NULL, NULL);
}