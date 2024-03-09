#include <bits/stdc++.h>
using namespace std;

// 1.
// Prims Algorithm
// Accepted
// Time efficiency better than Kruskals
class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<bool> vis(points.size());
        pq.push({0, 0});
        int mstWt = 0;

        while (!pq.empty())
        {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (vis[node])
                continue;
            vis[node] = true;
            mstWt += wt;

            for (int i = 0; i < points.size(); i++)
            {
                if (!vis[i])
                {
                    int nextNode = i;
                    int newWt = abs(points[node][0] - points[nextNode][0]) +
                                abs(points[node][1] - points[nextNode][1]);
                    pq.push({newWt, nextNode});
                }
            }
        }
        return mstWt;
    }
};

// 2.
// using Kruskal's approach to solve the problem
// but this give TLE -> 69/72  test cases passed

class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < points.size(); i++)
        {
            for (int j = i + 1; j < points.size(); j++)
            {
                if (i == j)
                    continue;
                int u = i;
                int v = j;
                int wt = abs(points[i][0] - points[j][0]) +
                         abs(points[i][1] - points[j][1]);

                edges.push_back({wt, {u, v}});
            }
        }

        // Soritng edges by weights
        sort(edges.begin(), edges.end());

        for (auto edge : edges)
            cout << edge.first << " " << edge.second.first << " "
                 << edge.second.second << endl;

        // DSU
        DisjointSet ds(points.size());
        vector<bool> vis(points.size(), false);

        int mstWt = 0;

        for (auto it : edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            // if there in diff component
            // join them

            if (ds.findUPar(u) != ds.findUPar(v))
            {
                mstWt += wt;
                ds.unionBySize(u, v);
            }
        }

        return mstWt;
    }
};

int main()
{
    vector<vector<int>> points = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
}