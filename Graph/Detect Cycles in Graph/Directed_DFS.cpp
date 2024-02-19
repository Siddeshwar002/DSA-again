#include <vector>
#include <stack>
using namespace std;

// parent child condition
// which worked in the case of undirected graph
// will not work int this case

bool isCycleUtil(int v, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &recStack)
{
    visited[v] = true;
    recStack[v] = true;

    for (int u : adj[v])
    {
        if (!visited[u])
        {
            if (isCycleUtil(u, adj, visited, recStack))
                return true;
        }

        // If the adjacent vertex is already in the recursive stack, a cycle is detected
        else if (recStack[u])
        {
            return true;
        }
    }

    // remove the node once after the recursion is completed
    recStack[v] = false;

    return false;
}

bool isCycle(int V, vector<vector<int>> &adj)
{
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);

    for (int v = 0; v < V; ++v)
    {
        if (!visited[v])
        {
            if (isCycleUtil(v, adj, visited, recStack))
                return true;
        }
    }

    return false;
}
