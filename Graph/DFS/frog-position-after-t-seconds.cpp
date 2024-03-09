// https://leetcode.com/problems/frog-position-after-t-seconds/

#include <bits/stdc++.h>
using namespace std;

// DFS approach
// Probability concepts

class Solution
{
public:
    void dfs(int node, vector<vector<int>> &edges, vector<int> &deg, vector<int> &vis, double &ans, int t, int target, double prob)
    {
        if (t < 0)
            return;
        if (target == node && (t == 0 || t > 0 && deg[node] == 0))
        {
            ans = prob;
            return;
        }
        if (deg[node] == 0)
            return;

        vis[node] = 1;
        double deno = deg[node];
        prob *= (1 / deno);

        for (auto nextNode : edges[node])
        {
            if (!vis[nextNode])
            {
                deg[nextNode]--;
                dfs(nextNode, edges, deg, vis, ans, t - 1, target, prob);
            }
        }
    }
    double frogPosition(int n, vector<vector<int>> &edges, int t, int target)
    {
        vector<int> vis(n + 1, 0);
        vector<int> deg(n + 1, 0);

        vector<vector<int>> adj(n + 1, vector<int>(n + 1));

        for (auto edge : edges)
        {
            deg[edge[0]]++;
            deg[edge[1]]++;
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        double ans = 0;
        dfs(1, adj, deg, vis, ans, t, target, 1);
        for (auto v : vis)
            cout << v << " ";
        return ans;
    }
};

// BFS solution
// TIME Efficient than the DFS
// when time is given -> always think of BFS solution
// all the nodes at the same level are having same time

class Solution
{
public:
    double frogPosition(int n, vector<vector<int>> &edges, int t, int target)
    {

        vector<vector<int>> graph(n + 1);
        for (auto e : edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<double> prob(n + 1, 0);

        vector<bool> visited(n + 1, 0);
        queue<int> q;
        q.push(1);
        visited[1] = 1;
        prob[1] = 1.0;

        while (!q.empty() && t--)
        {
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                int node = q.front();
                q.pop();

                // count of unvisited nodes from the current node.
                int edge_count = 0;

                for (auto v : graph[node])
                {
                    if (!visited[v])
                        edge_count++;
                }

                for (auto v : graph[node])
                {
                    if (!visited[v])
                    {
                        q.push(v);
                        visited[v] = true;
                        prob[v] = prob[node] / edge_count;
                    }
                }
                // the only tricky part
                // A frog cannot stay at a fixed postion until there's no more vertex to jump
                if (edge_count > 0)
                    prob[node] = 0;
            }
        }
        return prob[target];
    }
};
