#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dfs(int i, int j, vector<vector<bool>> &vis, vector<vector<int>> &matrix)
    {

        vis[i][j] = true;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        int res = 0;

        for (int k = 0; k < 4; k++)
        {
            int ni = i + dx[k];
            int nj = j + dy[k];

            int ans = 1;
            if (ni >= 0 && nj >= 0 && ni < matrix.size() && nj < matrix[0].size() && !vis[ni][nj] && matrix[ni][nj] < matrix[i][j])
            {
                ans = dfs(ni, nj, vis, matrix) + 1;
                vis[ni][nj] = false;
            }
            res = max(res, ans);
        }
        return res;
    }

    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();

        int ans = 1;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                vector<vector<bool>> vis(row, vector<bool>(col, false));
                ans = max(ans, dfs(i, j, vis, matrix));
            }
        }
        return ans;
    }
};