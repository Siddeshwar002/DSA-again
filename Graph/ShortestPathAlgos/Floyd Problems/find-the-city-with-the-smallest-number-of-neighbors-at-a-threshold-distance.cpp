#include <bits/stdc++.h>
using namespace std;

// Accepted
class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> adj(n, vector<int>(n, INT_MAX));

        // Construct Graph
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            adj[u][v] = wt;
            adj[v][u] = wt;
        }

        // Floyd Algorithm
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (adj[i][k] != INT_MAX && adj[k][j] != INT_MAX && i != j)
                        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }

        // Checking for node which has minReachable Nodes
        int ans = 0;
        int minReachable = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            int reachable = 0;
            for (int j = 0; j < n; j++)
            {
                if (adj[i][j] <= distanceThreshold)
                    reachable++;
            }
            if (reachable <= minReachable)
            {
                ans = i;
                minReachable = reachable;
            }
        }

        return ans;
    }
};