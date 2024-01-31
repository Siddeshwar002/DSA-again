#include <bits/stdc++.h>
using namespace std;

// No need of vis[i][j]
// because we can visit the same place again and again
// 3D dp array = dp[i][j][maxmoves]

class Solution
{
public:
    int totalPaths(int m, int n, int maxMove, int i, int j, vector<vector<vector<int>>> &dp)
    {
        const int MOD = 1e9 + 7;

        if (i < 0 || i >= m || j < 0 || j >= n)
        {
            // If the move goes out of bounds, return 1 only if maxMove is still positive
            return maxMove >= 0 ? 1 : 0;
        }

        if (maxMove == 0)
        {
            // No more moves left
            return 0;
        }

        if (dp[i][j][maxMove] != -1)
        {
            // If the result is already computed, return it
            return dp[i][j][maxMove];
        }

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        long long ans = 0;

        for (int k = 0; k < 4; k++)
        {
            int ni = i + dx[k];
            int nj = j + dy[k];

            // Recursive call for each possible move
            ans += totalPaths(m, n, maxMove - 1, ni, nj, dp);
            ans %= MOD;
        }

        // Save the result in the dp table and return
        return dp[i][j][maxMove] = ans;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return totalPaths(m, n, maxMove, startRow, startColumn, dp);
    }
};
