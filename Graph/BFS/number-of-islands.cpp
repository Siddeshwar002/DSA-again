#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<vector<char>> &grid, vector<vector<bool>> &vis, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || vis[i][j] || grid[i][j] == '0')
            return;

        vis[i][j] = true;
        solve(grid, vis, i - 1, j);
        solve(grid, vis, i, j + 1);
        solve(grid, vis, i + 1, j);
        solve(grid, vis, i, j - 1);

        return;
    }

    int numIslands(vector<vector<char>> &grid)
    {
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        int cnt = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1' && !vis[i][j])
                {
                    cnt++;
                    solve(grid, vis, i, j);
                }
            }
        }
        return cnt;
    }
};