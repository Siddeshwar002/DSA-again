#include <bits/stdc++.h>
using namespace std;

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i == 0 && j == 0)
                dp[0][0] = triangle[0][0];
            else if (j == 0)
                dp[i][j] = triangle[i][j] + dp[i - 1][j];
            else if (i == j)
                dp[i][j] = triangle[i][j] + dp[i - 1][j - 1];
            else
                dp[i][j] = triangle[i][j] + min(dp[i - 1][j], dp[i - 1][j - 1]);
        }
    }
    int ans = INT_MAX;
    for (int j = 0; j < n; j++)
    {
        ans = min(ans, dp[n - 1][j]);
    }
    return ans;
}