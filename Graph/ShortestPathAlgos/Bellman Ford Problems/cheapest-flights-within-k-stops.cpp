#include <bits/stdc++.h>
using namespace std;

// Refer below for multiple algo solutions

// 1. Bellman Ford Algorithm
// time efficient that others
// best suuits when some limitiations as Stops are given
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<int> distance(n, INT_MAX);
        distance[src] = 0;

        for (int i = 0; i <= k; ++i)
        {
            vector<int> temp(distance);
            for (const auto &flight : flights)
            {
                if (distance[flight[0]] != INT_MAX)
                {
                    temp[flight[1]] = min(temp[flight[1]], distance[flight[0]] + flight[2]);
                }
            }
            distance = temp;
        }

        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};

// 2.
// Using Distance array to avoid TLE
// to handle the new change
// we had to introduce one more array nodeStops
// Accepted

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto edge : flights)
        {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        vector<int> distance(n + 1, INT_MAX);
        vector<int> nodeStops(n + 1, 1);

        distance[src] = 0;
        pq.push({0, {src, 1}});
        while (!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second.first;
            int stops = pq.top().second.second;
            pq.pop();

            if (stops == k + 2 && node != dst)
                continue;
            if (stops <= k + 2 && node == dst)
                return dis;

            for (auto nextEdge : adj[node])
            {
                int nextDis = dis + nextEdge.second;

                // this condition avoids TLE
                if (nextDis >= distance[nextEdge.first] && stops + 1 >= nodeStops[nextEdge.first])
                    continue;
                nodeStops[nextEdge.first] = stops + 1;
                distance[nextEdge.first] = nextDis;
                pq.push({nextDis, {nextEdge.first, stops + 1}});
            }
        }
        return -1;
    }
};

// 3.
// gives TLE
// The usual Dijkstra's Algorithm

class Solution2
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto edge : flights)
        {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({0, {src, 1}});
        while (!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second.first;
            int stops = pq.top().second.second;
            pq.pop();

            if (stops == k + 2 && node != dst)
                continue;
            if (stops <= k + 2 && node == dst)
                return dis;

            for (auto nextEdge : adj[node])
            {
                int nextDis = dis + nextEdge.second;
                pq.push({nextDis, {nextEdge.first, stops + 1}});
            }
        }
        return -1;
    }
};

int main()
{
    int n = 5;
    vector<vector<int>> flights =
        {{0, 1, 5}, {1, 2, 5}, {0, 3, 2}, {3, 1, 2}, {1, 4, 1}, {4, 2, 1}};
    int src = 0;
    int dst = 2;
    int k = 2;

    Solution s;
    s.findCheapestPrice(n, flights, src, dst, k);
}