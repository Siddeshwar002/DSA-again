#include <vector>
#include <set>

using namespace std;

/**QUESTION :
 * https://www.geeksforgeeks.org/problems/maximum-connected-group/0
 *
 *
 */

class DisjointSet
{
public:
    vector<int> rank, parent, size;

    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
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
    int MaxConnection(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        // size = n*m
        DisjointSet dsu(n * m);

        // Directions for adjacent cells: up, right, down, left
        int d_row[] = {-1, 0, 1, 0};
        int d_col[] = {0, 1, 0, -1};

        // Step 1: Connect all `1`s in the grid
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        int n_row = i + d_row[k];
                        int n_col = j + d_col[k];
                        if (n_row >= 0 && n_row < n && n_col >= 0 && n_col < m && grid[n_row][n_col] == 1)
                        {
                            int node = i * m + j;
                            int adjNode = n_row * m + n_col;
                            dsu.unionBySize(node, adjNode);
                        }
                    }
                }
            }
        }

        // Step 2: Check maximum connection by converting a `0` to `1`
        int maxConnection = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                {
                    set<int> uniqueParents;
                    for (int k = 0; k < 4; k++)
                    {
                        int n_row = i + d_row[k];
                        int n_col = j + d_col[k];
                        if (n_row >= 0 && n_row < n && n_col >= 0 && n_col < m && grid[n_row][n_col] == 1)
                        {
                            int adjNode = n_row * m + n_col;
                            uniqueParents.insert(dsu.findUPar(adjNode));
                        }
                    }

                    // Calculate the size of the new connected component
                    int connectionSize = 1; // Adding the current `0` converted to `1`
                    for (auto parent : uniqueParents)
                    {
                        connectionSize += dsu.size[parent];
                    }

                    maxConnection = max(maxConnection, connectionSize);
                }
            }
        }

        // Step 3: If no `0` can be converted, return the size of the largest connected component
        for (int i = 0; i < n * m; i++)
        {
            maxConnection = max(maxConnection, dsu.size[dsu.findUPar(i)]);
        }

        return maxConnection;
    }
};