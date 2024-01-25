#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    int row = grid.size();
    int col = grid[0].size();

    vector<vector<int>> vis(row, vector<int>(col, 0));
    queue<pair<int, pair<int, int>>> qp;

    int time = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == 2)
            {
                qp.push({0, {i, j}});
                vis[i][j] = 1;
            }
        }
    }

    while (!qp.empty())
    {

        auto cur = qp.front();
        int curTime = cur.first;
        int curX = cur.second.first;
        int curY = cur.second.second;

        time = max(time, curTime);
        qp.pop();

        int dx[] = {0, -1, 0, 1};
        int dy[] = {-1, 0, 1, 0};

        for (int i = 0; i < 4; i++)
        {
            int ni = curX + dx[i];
            int nj = curY + dy[i];

            if (ni >= 0 && ni < row && nj >= 0 && nj < col && !vis[ni][nj] && grid[ni][nj] == 1)
            {
                grid[ni][nj] = 2;
                qp.push({curTime + 1, {ni, nj}});
            }
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == 1)
                return -1;
        }
    }

    return time;
}