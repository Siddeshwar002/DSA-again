#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// this give TLE 7/18 passed
class TreeAncestor
{
private:
    vector<int> Myparent;

public:
    TreeAncestor(int n, vector<int> &parent)
    {
        this->Myparent = parent;
    }

    int getKthAncestor(int node, int k)
    {

        while ((node < Myparent.size()) && Myparent[node] != -1 && k > 1)
        {
            node = Myparent[node];
            k--;
        }
        return Myparent[node];
    }
};

// $****************************************************************************************************
// wrong code - 11/17 passed

class TreeAncestor
{
private:
    vector<vector<int>> dp;
    int M = 0;

public:
    TreeAncestor(int n, vector<int> &parent)
    {

        int m = log2(n);
        M = m;
        dp.assign(m + 1, vector<int>(n, -1));

        for (int i = 1; i < n; i++)
        {
            dp[1][i] = parent[i];
        }

        for (int i = 2; i <= m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (dp[i - 1][j] != -1)
                    dp[i][j] = parent[dp[i - 1][j]];
            }
        }
    }

    int getKthAncestor(int node, int k)
    {
        if (k > M)
            return -1;
        return dp[k][node];
    }
};

// $****************************************************************************************************

