#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Correct solution but
// TLE
// 64 / 74 testcases passed
// should use DP
class Solution
{
public:
    void dfs(int u, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &dis)
    {
        vis[u] = true;

        for (auto v : adj[u])
        {
            if (!vis[v])
            {
                dis[v] = dis[u] + 1;
                dfs(v, adj, vis, dis);
            }
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n);

        for (auto edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
        {

            vector<bool> vis(n, 0);
            vector<int> dis(n, 0);

            dfs(i, adj, vis, dis);

            int sum = 0;
            for (auto d : dis)
                sum += d;

            ans[i] = sum;
        }
        return ans;
    }
};

// DP code
// Pending
