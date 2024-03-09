#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node)
    {
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); ++i)
        {
            int u = edges[i][0], v = edges[i][1];
            double prob = succProb[i];
            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }

        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});

        vector<bool> visited(n, false);

        while (!pq.empty())
        {
            double prob = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (visited[node])
                continue;

            visited[node] = true;

            if (node == end_node)
                return prob;

            for (auto &[nextNode, nextProb] : adj[node])
            {
                double newProb = prob * nextProb;
                pq.push({newProb, nextNode});
            }
        }

        return 0;
    }
};
