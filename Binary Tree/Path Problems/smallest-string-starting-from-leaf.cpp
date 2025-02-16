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

class Solution
{
public:
    void solve(TreeNode *root, string s, string &ans)
    {
        if (root->left == nullptr and root->right == nullptr)
        {

            char c = 'a' + root->val;
            s.insert(s.begin(), c);

            if (ans.size() == 0)
                ans = s;
            else
                ans = ans < s ? ans : s;
            return;
        }

        char c = 'a' + root->val;
        s.insert(s.begin(), c);

        if (root->left != nullptr)
            solve(root->left, s, ans);
        if (root->right != nullptr)
            solve(root->right, s, ans);

        return;
    }

    string smallestFromLeaf(TreeNode *root)
    {
        string ans = "";
        solve(root, "", ans);
        return ans;
    }
};