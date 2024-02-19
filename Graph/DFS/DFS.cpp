#include <vector>
#include <iostream>

using namespace std;

void dfs(int node, vector<bool> &visited, vector<vector<int>> &adj)
{
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, visited, adj);
        }
    }
}

void dfsTraversal(vector<vector<int>> &adj)
{
    int n = adj.size();

    vector<bool> visited(n, false);

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            dfs(i, visited, adj);
        }
    }
}

int main()
{
    // Example adjacency list representation of a graph
    vector<vector<int>> adj = {
        {1, 3},    // Node 0 is connected to nodes 1 and 3
        {0, 2, 3}, // Node 1 is connected to nodes 0, 2, and 3
        {1},       // Node 2 is connected to node 1
        {0, 1, 4}, // Node 3 is connected to nodes 0, 1, and 4
        {3}        // Node 4 is connected to node 3
    };

    cout << "DFS Traversal: ";
    dfsTraversal(adj);
    cout << endl;

    return 0;
}
