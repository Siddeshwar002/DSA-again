#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isBipartite(int V, vector<int> adj[])
    {
        vector<int> color(V, -1);

        for (int i = 0; i < V; ++i)
        {
            if (color[i] == -1)
            {
                queue<int> q;
                q.push(i);
                color[i] = 0;

                while (!q.empty())
                {
                    int node = q.front();
                    q.pop();

                    for (int neighbor : adj[node])
                    {
                        if (color[neighbor] == -1)
                        {
                            // If neighbor is uncolored
                            // Assign opposite color to neighbor

                            color[neighbor] = 1 - color[node];
                            q.push(neighbor);
                        }
                        else if (color[neighbor] == color[node])
                        {
                            // If neighbor has same color as node
                            // Graph is not bipartite
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    vector<int> adj[4];

    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);

    Solution obj;
    bool ans = obj.isBipartite(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";

    return 0;
}
