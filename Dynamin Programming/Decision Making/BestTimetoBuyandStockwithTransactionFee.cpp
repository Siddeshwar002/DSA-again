#include <vector>
using namespace std;

// Memoization
// Accepted

class Solution
{
public:
    int solve(vector<int> &prices, int idx, bool buy, vector<vector<int>> &memo, int fee)
    {
        if (idx >= prices.size())
            return 0;

        if (memo[idx][buy] != -1)
            return memo[idx][buy];

        if (buy)
        {
            int buyOption = solve(prices, idx + 1, !buy, memo, fee) - prices[idx];
            int skipOption = solve(prices, idx + 1, buy, memo, fee);
            return memo[idx][buy] = max(buyOption, skipOption);
        }
        else
        {
            // Fees
            int sellOption = solve(prices, idx + 1, !buy, memo, fee) + prices[idx] - fee;
            int skipOption = solve(prices, idx + 1, buy, memo, fee);
            return memo[idx][buy] = max(sellOption, skipOption);
        }
    }

    int maxProfit(vector<int> &prices, int fee)
    {
        vector<vector<int>> memo(prices.size() + 1, vector<int>(2, -1));
        return solve(prices, 0, true, memo, fee);
    }
};

// **********************************************************************************************************
// Tabualation
class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

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
                    // Fees
                    int sellOption = dp[idx + 1][!buy] + prices[idx] - fee;
                    int skipOption = dp[idx + 1][buy];
                    dp[idx][buy] = max(sellOption, skipOption);
                }
            }
        }

        return dp[0][1];
    }
};
