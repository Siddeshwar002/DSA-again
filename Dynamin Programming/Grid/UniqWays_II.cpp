#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();

        vector<vector<int>> dp(row, vector<int>(col, 1));

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
            }
        }

        for (int i = 1; i < row; i++)
        {
            if (dp[i - 1][0] == 0)
                dp[i][0] = 0;
        }

        for (int i = 1; i < col; i++)
        {
            if (dp[0][i - 1] == 0)
                dp[0][i] = 0;
        }

        for (int i = 1; i < row; i++)
        {
            for (int j = 1; j < col; j++)
            {
                if (obstacleGrid[i][j] == 1)
                    continue;

                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[row - 1][col - 1];
    }
};