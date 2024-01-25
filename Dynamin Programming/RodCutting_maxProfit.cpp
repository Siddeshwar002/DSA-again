#include <bits/stdc++.h>
using namespace std;

int MaxProfit(int price[], int n, int i, vector<vector<int>> &dp)
{
    if (i == 0)
        // * return n * price[0];
        return dp[i][n] = 0;

    if (dp[i][n] != -1)
        return dp[i][n];

    if (n - i >= 0)
    {
        // * Here you can either consider or Not consider
        return dp[i][n] = max(price[i - 1] + MaxProfit(price, n - i, i, dp),
                              MaxProfit(price, n, i - 1, dp));
    }
    else
    {
        return dp[i][n] = MaxProfit(price, n, i - 1, dp);
    }
}

int cutRod(int price[], int n)
{

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return MaxProfit(price, n, n, dp);
}