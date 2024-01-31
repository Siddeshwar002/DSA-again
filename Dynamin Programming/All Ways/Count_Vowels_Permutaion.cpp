#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    const int MOD = 1000000007;

    int dfsVowels(vector<vector<int>> &adj, int n, int start, vector<vector<int>> &dp)
    {

        if (n == 0)
            return dp[start][n] = 1;

        if (dp[start][n] != -1)
            return dp[start][n];

        int ans = 0;
        for (auto next : adj[start])
        {
            ans += dfsVowels(adj, n - 1, next, dp);
            ans %= MOD;
        }
        return dp[start][n] = ans;
    }

    int countVowelPermutation(int n)
    {
        vector<vector<int>> adj = {{1}, {0, 2}, {0, 1, 3, 4}, {2, 4}, {0}};
        vector<vector<int>> dp(5, vector<int>(n + 1, -1));

        int ans = 0;
        for (int i = 0; i <= 4; i++)
        {
            ans += dfsVowels(adj, n - 1, i, dp);
            ans %= MOD;
        }
        return ans;
    }
};
