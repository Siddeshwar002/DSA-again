#include <bits/stdc++.h>
using namespace std;

// ! combinations
int uniquePaths(int m, int n)
{
    // Calculate m + n - 2 factorial
    long long paths = 1;
    for (int i = n; i <= m + n - 2; ++i)
    {
        paths *= i;
        paths /= (i - n + 1);
    }
    return paths;
}

// ! DP  : Tabulation
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 1));
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}
