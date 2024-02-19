#include <vector>
#include <stack>

using namespace std;

bool DFS_isCycle(int v, vector<int> adj[], vector<bool> &visited, int parent)
{
    visited[v] = true;

    for (int u : adj[v])
    {
        if (!visited[u])
        {
            if (DFS_isCycle(u, adj, visited, v))
                return true;
        }
        else if (u != parent)
        {
            return true;
        }
    }

    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);

    for (int v = 0; v < V; ++v)
    {
        if (!visited[v])
        {
            if (DFS_isCycle(v, adj, visited, -1))
                return true;
        }
    }

    return false;
}
