#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Memory Limit Execeded
class Solution
{
public:
    map<int, int> solve(int n, vector<vector<int>> &adj, string labels, int Node, vector<bool> &vis, vector<int> &ans)
    {
        vis[Node] = 1;

        map<int, int> mp;
        mp[labels[Node] - '0']++;

        for (auto nextNode : adj[Node])
        {
            if (!vis[nextNode])
            {
                map<int, int> nextMap = solve(n, adj, labels, nextNode, vis, ans);
                for (auto ele : nextMap)
                {
                    mp[ele.first] += ele.second;
                }
            }
        }
        ans[Node] = mp[labels[Node] - '0'];
        return mp;
    }

    vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels)
    {
        vector<int> ans(n, 0);
        vector<bool> vis(n, 0);

        vector<vector<int>> adj(n);

        for (auto edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int Node = 0;
        solve(n, adj, labels, Node, vis, ans);
        return ans;
    }
};

// Use vector instead of maps
class Solution
{
public:
    vector<int> fun(vector<vector<int>> &adj, string &labels, int i, vector<int> &result)
    {
        vector<int> ans(26, 0);
        result[i] = 1;
        ans[labels[i] - 'a'] = 1;

        for (int j = 0; j != adj[i].size(); j++)
            if (!result[adj[i][j]])
            {
                vector<int> tmp = fun(adj, labels, adj[i][j], result);
                for (int k = 0; k != 26; k++)
                    ans[k] += tmp[k];
            }

        result[i] = ans[labels[i] - 'a'];

        return ans;
    }

    vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels)
    {
        vector<vector<int>> adj(n);
        vector<int> result(n, 0);
        for (int i = 0; i != edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        fun(adj, labels, 0, result);
        return result;
    }
};