#include <bits/stdc++.h>
using namespace std;

// ! DP : Memoization
// * This get accepted too

int coinChange(int amt, int idx, vector<int> &coins, vector<vector<int>> &dp)
{
    if (amt == 0)
        return 1;
    if (idx < 0)
        return 0;

    if (dp[idx][amt] != -1)
        return dp[idx][amt];

    int consider = 0, notConsider = 0;

    if (coins[idx] <= amt)
        consider = coinChange(amt - coins[idx], idx, coins, dp);

    notConsider = coinChange(amt, idx - 1, coins, dp);

    return dp[idx][amt] = consider + notConsider;
}

int change(int amt, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amt + 1, -1));
    return coinChange(amt, n - 1, coins, dp);
}

// ! *********************************************************************************
// ! Tabulation :
// * Better CODE

int change(int amt, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amt + 1, 0));

    // * Base case: When the amount is zero,
    // * there's always one way to make zero using coins (by using no coins)
    for (int i = 0; i <= n; ++i)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= amt; ++j)
        {
            if (coins[i - 1] <= j)
            {
                // * Number of ways using current coin + Number of ways without using the current coin
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
            }
            else
            {
                // * Just use the number of ways without using the current coin
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][amt];
}

int main()
{
    vector<int> coins = {1, 2, 5};
    cout << change(5, coins) << endl;
}