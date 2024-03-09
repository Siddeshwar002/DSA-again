#include <bits/stdc++.h>
using namespace std;

// 1.
// DFS
// Accepted

class Solution
{
public:
    void dfs(vector<vector<pair<int, int>>> &adj, vector<int> &vis, int start,
             int dis, int &cnt, int signalSpeed)
    {
        if (dis % signalSpeed == 0)
            cnt++;
        vis[start] = true;

        for (auto nextnode : adj[start])
        {
            if (!vis[nextnode.first])
                dfs(adj, vis, nextnode.first, nextnode.second + dis, cnt,
                    signalSpeed);
        }
        return;
    }

    vector<int> countPairsOfConnectableServers(vector<vector<int>> &edges,
                                               int signalSpeed)
    {
        int n = edges.size();

        // Graph construction
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto edge : edges)
        {
            cout << edge[0] << " " << edge[1] << " " << edge[2] << endl;
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<int> res;

        // Counting pairs for each node
        // So start DFS from each node as starting node
        for (int i = 0; i < n + 1; i++)
        {
            vector<int> vis(n + 1, false);
            vector<int> ans;
            vis[i] = true;

            // Doing dfs from the neighboring node of the parent node
            // To avoid the path overlapping
            for (auto nextNode : adj[i])
            {
                int cnt = 0;
                dfs(adj, vis, nextNode.first, nextNode.second, cnt,
                    signalSpeed);
                ans.push_back(cnt);
            }

            int curAns = 0;

            // calculating the total number of combinations
            while (ans.size() > 1)
            {
                int n1 = ans[0];
                int n2 = ans[1];

                ans.erase(ans.begin());
                ans.erase(ans.begin());

                curAns += (n1 * n2);
                ans.insert(ans.begin(), n1 + n2);
            }
            res.push_back(curAns);
        }
        return res;
    }
};

// 2.
// Same approach better code
// Try to understand the Distance modification
// Beats 99% of the c++ submissions

class Solution
{
public:
    int dfs(int i, int p, vector<vector<pair<int, int>>> &adj, int s, int signalSpeed)
    {
        int c = 0;
        if (s == 0)
            c++;
        for (auto &u : adj[i])
        {
            if (u.first == p)
                continue;
            c += dfs(u.first, i, adj, (s - u.second % signalSpeed + signalSpeed) % signalSpeed, signalSpeed);
        }
        return c;
    }

    vector<int> countPairsOfConnectableServers(vector<vector<int>> &edges, int signalSpeed)
    {
        int n = edges.size() + 1;
        vector<int> ans(n);
        vector<vector<pair<int, int>>> adj(n);
        for (auto &edge : edges)
        {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        for (int i = 0; i < n; i++)
        {
            int temp = 0, sum = 0;
            if (adj[i].size() == 1)
            {
                temp = 0;
            }
            else
            {
                for (auto &u : adj[i])
                {
                    int current = dfs(u.first, i, adj, (signalSpeed - u.second % signalSpeed) % signalSpeed, signalSpeed);
                    temp += sum * current;
                    sum += current;
                }
            }
            ans[i] = temp;
        }
        return ans;
    }
};