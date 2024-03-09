#include <bits/stdc++.h>
using namespace std;

// DFS withuot constructing the graph
// Union Find is time efficient

class Solution
{
public:
    int dfs(vector<vector<int>> &stones, int index, vector<bool> &visited, int &n)
    {
        visited[index] = true;

        // result is assignd with 0 instead of 1
        // becuse we cant remove the last node of the connected components
        int result = 0;

        // dfs withuot constructing the graph
        for (int i = 0; i < n; i++)
            if (!visited[i] && (stones[i][0] == stones[index][0] || stones[i][1] == stones[index][1]))
                result += (dfs(stones, i, visited, n) + 1);
        return result;
    }

    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        vector<bool> visited(n, 0);
        int result = 0;

        // Calling DFS for all the not visited nodes
        for (int i = 0; i < n; i++)
        {
            if (visited[i])
            {
                continue;
            }
            result += dfs(stones, i, visited, n);
        }
        return result;
    }
};

// $******************************************************************************************

// Approch 2:
// Union Find Approach
// Efficient approach

class Solution
{
public:
    vector<int> parent; // Vector to store the parent indices of stones

    int removeStones(vector<vector<int>> &stones)
    {
        // Maps to store stone indices based on row and column values
        unordered_map<int, vector<int>> rowmap, colmap;

        // Populate the rowmap and colmap
        for (int i = 0; i < stones.size(); i++)
        {
            rowmap[stones[i][0]].push_back(i); // Store stone indices by row value
            colmap[stones[i][1]].push_back(i); // Store stone indices by column value
        }

        // Initialize the parent vector with indices
        for (int i = 0; i < stones.size(); i++)
            parent.push_back(i);

        // Union stones based on the same row or column
        for (int i = 0; i < stones.size(); i++)
        {
            // Union stones in the same row
            for (int j : rowmap[stones[i][0]])
                unite(i, j);
            // Union stones in the same column
            for (int j : colmap[stones[i][1]])
                unite(i, j);
        }

        // Find unique groups of stones
        unordered_set<int> unique;
        for (int n : parent)
            unique.insert(find(n));

        // Calculate and return the result
        return stones.size() - unique.size();
    }

    // Find function to find the ultimate parent of a stone index
    int find(int n)
    {
        return parent[n] == n ? n : parent[n] = find(parent[n]);
    }

    // Union function to unite stones with the same parent
    void unite(int a, int b)
    {
        parent[find(a)] = find(b);
    }
};