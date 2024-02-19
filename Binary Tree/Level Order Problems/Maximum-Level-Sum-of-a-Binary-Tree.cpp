#include <queue>
#include <climits> // For INT_MIN
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxLevelSum(TreeNode *root)
{
    if (!root)
        return 0;

    queue<TreeNode *> q;
    q.push(root);
    int maxLevel = 0;
    int maxSum = INT_MIN;

    int level = 1;
    while (!q.empty())
    {
        int levelSum = 0;
        int size = q.size();

        // untill the current level is completely traversed
        // no need to use NULL to differntiate the levels
        for (int i = 0; i < size; ++i)
        {
            TreeNode *node = q.front();
            q.pop();
            levelSum += node->val;

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }

        if (levelSum > maxSum)
        {
            maxSum = levelSum;
            maxLevel = level;
        }

        ++level;
    }

    return maxLevel;
}
