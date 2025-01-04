// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/?envType=list&envId=55af7bu7

// #include <bits/stdc++.h>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
using namespace std;

// Approach 1 :
// Stack Approach of Question.II, won't work here
// you need to choose at most only two transactions
// such that they should maximize the profit
// how do you know which two transactions are profitable ?
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit1 = 0, profit2 = 0;

        stack<int> st;
        for (auto ele : prices)
        {
            if (st.empty())
                st.push(ele);
            else if (st.size() == 1 && st.top() > ele)
            {
                st.pop();
                st.push(ele);
            }
            else if (st.size() == 2 && st.top() > ele)
            {
                int F = st.top();
                st.pop();
                int S = st.top();
                st.pop();
                st.push(ele);

                if (profit1 == 0)
                {
                    profit1 += (F - S);
                    continue;
                }

                if (profit2 == 0)
                {
                    profit2 += (F - S);
                    continue;
                }

                if (profit1 != 0 && profit2 != 0)
                {
                    int curProfit = (F - S);
                    profit1 = max(profit1, profit2);
                    profit2 = max(profit2, curProfit);
                }
            }
            else if (st.size() == 1 && st.top() < ele)
            {
                st.push(ele);
            }
            else if (st.size() == 2 && st.top() < ele)
            {
                st.pop();
                st.push(ele);
            }
        }

        if (st.size() == 2)
        {
            int F = st.top();
            st.pop();
            int S = st.top();
            st.pop();

            if (profit1 == 0)
            {
                profit1 += (F - S);
            }

            else if (profit2 == 0)
            {
                profit2 += (F - S);
            }

            else if (profit1 != 0 && profit2 != 0)
            {
                int curProfit = (F - S);
                profit1 = max(profit1, profit2);
                profit2 = max(profit2, curProfit);
            }
        }
        return profit1 + profit2;
    }
};

// *****************************************************************************************************

// Approach 2 :
// Memoization
// Accepted

class Solution
{
public:
    int solve(vector<int> &prices, int idx, int transactions, bool buy, vector<vector<vector<int>>> &memo)
    {
        if (idx == prices.size() || transactions == 0)
            return 0;

        if (memo[idx][buy][transactions] != -1)
            return memo[idx][buy][transactions];

        if (buy)
        {
            int buyOption = solve(prices, idx + 1, transactions, !buy, memo) - prices[idx];
            int skipOption = solve(prices, idx + 1, transactions, buy, memo);
            return memo[idx][buy][transactions] = max(buyOption, skipOption);
        }
        else
        {
            int sellOption = solve(prices, idx + 1, transactions - 1, !buy, memo) + prices[idx];
            int skipOption = solve(prices, idx + 1, transactions, buy, memo);
            return memo[idx][buy][transactions] = max(sellOption, skipOption);
        }
    }

    int maxProfit(vector<int> &prices)
    {
        vector<vector<vector<int>>> memo(prices.size() + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(prices, 0, 2, true, memo);
    }
};

// *****************************************************************************************************
// Approach 3 :
// Tabulation
// Accepted

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int transactions = 0; transactions <= 2; transactions++)
                {
                    if (buy == 1)
                    {
                        int buyOption = dp[idx + 1][!buy][transactions] - prices[idx];
                        int skipOption = dp[idx + 1][buy][transactions];
                        dp[idx][buy][transactions] = max(buyOption, skipOption);
                    }
                    else
                    {
                        // base condition : Ensure transactions > 0 before considering sell option
                        int sellOption = (transactions > 0) ? dp[idx + 1][!buy][transactions - 1] + prices[idx] : 0;
                        int skipOption = dp[idx + 1][buy][transactions];
                        dp[idx][buy][transactions] = max(sellOption, skipOption);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};
