#include <bits/stdc++.h>
using namespace std;

// ! Memo
// * Beats 84%

class Solution
{
public:
    int minCoins(vector<int> &coins, int amt, int n, vector<vector<int>> &memo)
    {
        if (amt == 0)
            return 0;

        if (n == coins.size())
            return INT_MAX;

        if (memo[n][amt] != -1)
            return memo[n][amt];

        int consider = INT_MAX, notConsider = INT_MAX;
        if (coins[n] <= amt)
        {
            consider = minCoins(coins, amt - coins[n], n, memo);
            if (consider != INT_MAX)
                consider += 1;
        }

        notConsider = minCoins(coins, amt, n + 1, memo);

        return memo[n][amt] = min(consider, notConsider);
    }

    int coinChange(vector<int> &coins, int amount)
    {
        vector<vector<int>> memo(coins.size() + 1, vector<int>(amount + 1, -1));
        int result = minCoins(coins, amount, 0, memo);
        return (result == INT_MAX) ? -1 : result;
    }
};

// ! *************************************************************************************
// * Tabulation
// * Beats 80%

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INT_MAX));

        // Base case: If the amount is 0, 0 coins are needed.
        for (int i = 0; i <= n; ++i)
        {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= amount; ++j)
            {

                if (coins[i - 1] <= j)
                {
                    int consider = dp[i][j - coins[i - 1]];
                    if (consider != INT_MAX)
                    {
                        dp[i][j] = min(dp[i][j], consider + 1);
                    }
                }

                // Skip the current coin
                // Not consider
                dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            }
        }

        return (dp[n][amount] == INT_MAX) ? -1 : dp[n][amount];
    }
};