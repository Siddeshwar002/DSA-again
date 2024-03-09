#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        // you need to initialize vector before using
        // if you dont know the node values
        // then its better to use map<int,vector<int>> mp

        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto edge : times)
            adj[edge[0]].push_back({edge[1], edge[2]});

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k});
        vector<bool> vis(n, false);
        int res = 0;

        while (!pq.empty())
        {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            if (vis[node])
                continue;

            n--;
            vis[node] = true;
            res = dis;

            for (auto edge : adj[node])
            {
                pq.push({edge.second + dis, edge.first});
            }
        }

        if (n == 0)
            return res;
        else
            return -1;
    }
};