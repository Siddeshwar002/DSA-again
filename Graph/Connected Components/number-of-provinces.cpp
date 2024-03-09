#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int start, vector<vector<int>> &isConnected, vector<bool> &visited)
    {
        visited[start] = true;

        for (int i = 0; i < isConnected.size(); i++)
        {
            if (start != i && !visited[i] && isConnected[start][i])
                dfs(i, isConnected, visited);
        }
        return;
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        vector<bool> visited(isConnected.size(), false);
        int res = 0;

        // perform DFS from all the nodes
        for (int i = 0; i < isConnected.size(); i++)
        {
            if (!visited[i])
            {
                res++;
                dfs(i, isConnected, visited);
            }
        }
        return res;
    }
};