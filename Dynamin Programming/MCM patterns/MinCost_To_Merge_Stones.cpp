#include <bits/stdc++.h>
using namespace std;

// Tabulation
class Solution
{
public:
    int mergeStones(vector<int> &stones, int k)
    {
        int n = stones.size();
        if ((n - k) % (k - 1) != 0)
            return -1;

        vector<int> cumSum(n + 1, 0);
        cumSum[0] = 0;

        for (int i = 0; i < n; i++)
            cumSum[i + 1] = cumSum[i] + stones[i];

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int len = k - 1; len < n; len++)
        {
            for (int x = 0, y = x + len; x < n && y < n; x++, y++)
            {

                if (len == k - 1)
                    dp[x][y] = cumSum[y + 1] - cumSum[x];

                else
                {
                    dp[x][y] = INT_MAX;

                    // Split the problem
                    for (int mid = x; mid < y; mid += k - 1)
                        dp[x][y] = min(dp[x][y], dp[x][mid] + dp[mid + 1][y]);

                    // Current Problem
                    if (len % (k - 1) == 0)
                        dp[x][y] += cumSum[y + 1] - cumSum[x];
                }
            }
        }
        return dp[0][n - 1] != INT_MAX ? dp[0][n - 1] : -1;
    }
};

// ***************************************************************************************
// Tabulation

class Solution
{
public:
    int mergeStones(vector<int> &stones, int K)
    {
        int n = stones.size();

        if ((n - 1) % (K - 1) != 0)
        {
            return -1;
        }

        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i)
        {
            prefixSum[i + 1] = prefixSum[i] + stones[i];
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int len = K; len <= n; ++len)
        {
            for (int i = 0; i + len <= n; ++i)
            {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;

                for (int mid = i; mid < j; mid += K - 1)
                {
                    dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j]);
                }

                if ((len - 1) % (K - 1) == 0)
                {
                    dp[i][j] += prefixSum[j + 1] - prefixSum[i];
                }
            }
        }

        return dp[0][n - 1];
    }
};