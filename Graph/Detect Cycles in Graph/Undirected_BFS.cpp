#include <vector>
#include <queue>
#include <iostream>

using namespace std;

bool isCycle(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);

    for (int i = 0; i < V; ++i)
    {
        if (!visited[i])
        {
            queue<pair<int, int>> q;
            q.push({i, -1}); // {vertex, parent}
            visited[i] = true;

            while (!q.empty())
            {
                int v = q.front().first;
                int parent = q.front().second;
                q.pop();

                for (int u : adj[v])
                {
                    if (!visited[u])
                    {
                        visited[u] = true;
                        q.push({u, v}); // {vertex, parent}
                    }
                    else if (u != parent)
                    {
                        // u is visited and not the parent of v, cycle detected
                        return true;
                    }
                }
            }
        }
    }

    return false;
}
