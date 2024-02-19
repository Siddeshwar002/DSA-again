#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// easy
// DFS

class Solution
{
public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> paths;
        if (root == nullptr)
        {
            return paths;
        }
        dfs(root, "", paths);
        return paths;
    }

    void dfs(TreeNode *node, string path, vector<string> &paths)
    {
        // Append the current node's value to the path
        if (!path.empty())
        {
            path += "->";
        }
        path += to_string(node->val);

        // If it's a leaf node, add the path to the result
        if (node->left == nullptr && node->right == nullptr)
        {
            paths.push_back(path);
            return;
        }

        // Continue DFS for left and right subtrees
        if (node->left != nullptr)
            dfs(node->left, path, paths);
        if (node->right != nullptr)
            dfs(node->right, path, paths);
    }
};
