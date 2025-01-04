// #include <bits/stdc++.h>
#include<vector>
using namespace std;

int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    int ans = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0)
                dp[i][j] = matrix[i][j];
            else if (j == 0)
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + 1]) + matrix[i][j];
            else if (j == n - 1)
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + matrix[i][j];
            else
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i - 1][j + 1])) + matrix[i][j];

            if (i == n - 1)
                ans = min(ans, dp[i][j]);
        }
    }
    return ans;
}