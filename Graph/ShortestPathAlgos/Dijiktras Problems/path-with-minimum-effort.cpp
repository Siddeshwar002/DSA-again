#include <bits/stdc++.h>
using namespace std;

// This problems helped me get the real intuition of
// Dijkstra's algorithm

class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int n = heights.size();
        int m = heights[0].size();
        if (n == 1 && m == 1)
            return 0;

        vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<vector<int>> minEffort(n, vector<int>(m, INT_MAX));
        pq.push({0, {0, 0}});
        minEffort[0][0] = 0;

        while (!pq.empty())
        {
            auto [effort, cell] = pq.top();
            pq.pop();

            int i = cell.first;
            int j = cell.second;

            if (i == n - 1 && j == m - 1)
            {
                return effort;
            }

            visited[i][j] = true;

            for (auto &dir : directions)
            {
                int ni = i + dir[0];
                int nj = j + dir[1];

                if (ni >= 0 && ni < n && nj >= 0 && nj < m && !visited[ni][nj])
                {
                    int newEffort = max(effort, abs(heights[i][j] - heights[ni][nj]));

                    if (newEffort < minEffort[ni][nj])
                    {
                        minEffort[ni][nj] = newEffort;
                        pq.push({newEffort, {ni, nj}});
                    }
                }
            }
        }

        return -1;
    }
};
// $**********************************************************************************************

// TLE
// Matrix Traversal -> recursive solution
// Too much of a time consuming
// Try something different

class Solution
{
public:
    void gridTraversal(int i, int j, int row, int col,
                       vector<vector<bool>> &vis, vector<vector<int>> &heights,
                       int &ans, int &res)
    {

        vis[i][j] = true;

        if (i == row - 1 && j == col - 1)
        {
            res = min(res, ans);
            return;
        }
        vector<vector<int>> direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        for (int k = 0; k < 4; k++)
        {
            int ni = i + direction[k][0];
            int nj = j + direction[k][1];

            if (ni >= 0 && nj >= 0 && ni < row && nj < col && !vis[ni][nj])
            {
                ans = max(ans, abs(heights[i][j] - heights[ni][nj]));
                gridTraversal(ni, nj, row, col, vis, heights, ans, res);
                ans = INT_MIN;
                vis[ni][nj] = false;
            }
        }
        return;
    }

    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int n = heights.size();
        int m = heights[0].size();
        if (n == 1 && m == 1)
            return 0;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int ans = INT_MIN;
        int res = INT_MAX;
        gridTraversal(0, 0, n, m, vis, heights, ans, res);
        return res;
    }
};