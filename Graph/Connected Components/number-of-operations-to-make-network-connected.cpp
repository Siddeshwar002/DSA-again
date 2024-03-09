#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int start, map<int, vector<int>> &adj, vector<bool> &visited)
    {
        visited[start] = true;

        for (auto nextNode : adj[start])
        {
            if (!visited[nextNode])
            {
                dfs(nextNode, adj, visited);
            }
        }
        return;
    }

    int makeConnected(int n, vector<vector<int>> &connections)
    {
        map<int, vector<int>> adj;

        if (connections.size() < n - 1)
            return -1;

        for (auto edge : connections)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, adj, visited);
                res++;
            }
        }
        return res - 1;
    }
};