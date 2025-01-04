// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/?envType=list&envId=55af7bu7

#include <vector>
#include <string>
#include <iostream>
#include <stack>
using namespace std;

// Tabulatino
// Accepted

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int transactions = 0; transactions <= k; transactions++)
                {
                    if (buy == 1)
                    {
                        int buyOption = dp[idx + 1][!buy][transactions] - prices[idx];
                        int skipOption = dp[idx + 1][buy][transactions];
                        dp[idx][buy][transactions] = max(buyOption, skipOption);
                    }
                    else
                    {
                        // Ensure transactions > 0 before considering sell option
                        int sellOption = (transactions > 0) ? dp[idx + 1][!buy][transactions - 1] + prices[idx] : 0;
                        int skipOption = dp[idx + 1][buy][transactions];
                        dp[idx][buy][transactions] = max(sellOption, skipOption);
                    }
                }
            }
        }
        return dp[0][1][k];
    }
};
