#include <vector>
#include <queue>
#include <iostream>

using namespace std;

void bfsTraversal(vector<vector<int>> &adj, int startNode)
{
    int n = adj.size();
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(startNode);

    // you usually dont need vis array for tree
    // but you need it for graph

    visited[startNode] = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        // for tree :
        // push leftChild and RightChild into the queue

        // for Graph :
        // Push all the neighbours

        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    cout << endl;
}

int main()
{
    vector<vector<int>> adj = {
        {1, 3},
        {0, 2, 3},
        {1},
        {0, 1, 4},
        {3}};
    bfsTraversal(adj, 0);
    return 0;
}
