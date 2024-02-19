#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild)
    {

        vector<int> parent(n, -1);

        for (int i = 0; i < n; i++)
        {

            if (leftChild[i] != -1)
            {
                if (parent[leftChild[i]] == -1)
                    parent[leftChild[i]] = i;
                else
                    return false;
            }

            if (rightChild[i] != -1)
            {
                if (parent[rightChild[i]] == -1)
                    parent[rightChild[i]] = i;
                else
                    return false;
            }
        }

        int par;
        for (int i = 0; i < n; i++)
        {
            int node = i;
            while (parent[node] != -1)
            {
                node = parent[node];
                parent[i] = node;
                if (i == node)
                    return false;
            }
            par = node;
        }

        for (int i = 0; i < n; i++)
        {
            if (parent[par] != -1)
                return false;

            if (i != par && parent[i] != par)
                return false;
        }
        return true;
    }
};