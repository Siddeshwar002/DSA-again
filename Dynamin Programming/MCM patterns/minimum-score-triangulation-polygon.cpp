#include <bits/stdc++.h>
using namespace std;

// Memoization

class Solution
{
public:
    int solveMemo(vector<int> &v, int i, int j, vector<vector<int>> &memo)
    {
        if (i + 1 == j)
            return 0;

        if (memo[i][j] != -1)
            return memo[i][j];

        int ans = INT_MAX;
        for (int k = i + 1; k < j; k++)
        {
            ans = min(ans, (v[i] * v[k] * v[j]) + solveMemo(v, i, k, memo) + solveMemo(v, k, j, memo));
        }
        return memo[i][j] = ans;
    }
    int minScoreTriangulation(vector<int> &values)
    {
        vector<vector<int>> memo(values.size(), vector<int>(values.size(), -1));
        return solveMemo(values, 0, values.size() - 1, memo);
    }
};

// *************************************************************************
// Tabulation

class Solution
{
public:
    int minScoreTriangulation(vector<int> &values)
    {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int len = 3; len <= n; ++len)
        {
            for (int i = 0; i + len - 1 < n; ++i)
            {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;

                for (int k = i + 1; k < j; ++k)
                {
                    dp[i][j] = min(dp[i][j], values[i] * values[k] * values[j] + dp[i][k] + dp[k][j]);
                }
            }
        }

        return dp[0][n - 1];
    }
};
