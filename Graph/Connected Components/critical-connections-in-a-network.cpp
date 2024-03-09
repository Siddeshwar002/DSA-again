#include <bits/stdc++.h>
using namespace std;

// Accepted

class Solution
{
public:
    void dfs(int start, int parent, vector<int> adj[],
             vector<bool> &visited, vector<int> &time, int &curTime,
             vector<int> &lowTime, vector<vector<int>> &res)
    {
        visited[start] = true;
        time[start] = curTime;
        lowTime[start] = curTime;
        curTime++;

        for (auto nextNode : adj[start])
        {
            if (nextNode != parent)
            {
                if (!visited[nextNode])
                {
                    visited[nextNode] = true;
                    dfs(nextNode, start, adj, visited, time, curTime, lowTime, res);
                    if (time[start] < lowTime[nextNode])
                        res.push_back({start, nextNode});
                }

                lowTime[start] = min(lowTime[start], lowTime[nextNode]);
            }
        }
        return;
    }

    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>> &connections)
    {

        // Using this give TLE for large inputs
        // Prefer using vector<int> adj[] over maps

        // map<int, vector<int>> adj;
        // for (auto edge : connections) {
        //     adj[edge[0]].push_back(edge[1]);
        //     adj[edge[1]].push_back(edge[0]);
        // }

        vector<int> adj[n];
        for (auto it : connections)
        {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> time(n);
        vector<int> lowTime(n);
        vector<bool> visited(n, false);
        vector<vector<int>> res;
        int curTime = 1;

        dfs(0, -1, adj, visited, time, curTime, lowTime, res);
        return res;
    }
};