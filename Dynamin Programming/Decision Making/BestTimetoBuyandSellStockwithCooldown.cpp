// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/?envType=list&envId=55af7bu7

// #include <bits/stdc++.h>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
using namespace std;

// Memoization
// Accepted

class Solution
{
public:
    int solve(vector<int> &prices, int idx, bool buy, vector<vector<int>> &memo)
    {
        if (idx >= prices.size())
            return 0;

        if (memo[idx][buy] != -1)
            return memo[idx][buy];

        if (buy)
        {
            int buyOption = solve(prices, idx + 1, !buy, memo) - prices[idx];
            int skipOption = solve(prices, idx + 1, buy, memo);
            return memo[idx][buy] = max(buyOption, skipOption);
        }
        else
        {
            // Cooldown idx + 2
            int sellOption = solve(prices, idx + 2, !buy, memo) + prices[idx];
            int skipOption = solve(prices, idx + 1, buy, memo);
            return memo[idx][buy] = max(sellOption, skipOption);
        }
    }

    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> memo(prices.size() + 1, vector<int>(2, -1));
        return solve(prices, 0, true, memo);
    }
};

// ******************************************************************************************************
// Tabulation
// Accepted
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (bool buy : {true, false})
            {
                if (buy)
                {
                    int buyOption = dp[idx + 1][!buy] - prices[idx];
                    int skipOption = dp[idx + 1][buy];
                    dp[idx][buy] = max(buyOption, skipOption);
                }
                else
                {
                    // Cooldown idx + 2
                    int sellOption = dp[idx + 2][!buy] + prices[idx];
                    int skipOption = dp[idx + 1][buy];
                    dp[idx][buy] = max(sellOption, skipOption);
                }
            }
        }

        return dp[0][1];
    }
};
