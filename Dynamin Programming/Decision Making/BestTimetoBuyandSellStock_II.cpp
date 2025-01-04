// https : // leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

// #include <bits/stdc++.h>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
using namespace std;

// Stack Approach
// TC : O(N)
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;

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
                profit += (F - S);
                st.push(ele);
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

            profit += (F - S);
        }
        return profit;
    }
};

// *****************************************************************************************************
// One-pass solutino
// without using stack

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;

        for (int i = 1; i < prices.size(); ++i)
        {
            // If the current price is greater than the previous one, add the difference to profit
            if (prices[i] > prices[i - 1])
            {
                profit += prices[i] - prices[i - 1];
            }
        }

        return profit;
    }
};

// *****************************************************************************************************
// Memoization :

long getAns(long *Arr, int ind, int buy, int n, vector<vector<long>> &dp)
{
    if (ind == n)
        return 0;

    if (dp[ind][buy] != -1)
        return dp[ind][buy];

    long profit = 0;

    if (buy == 0)
        profit = max(0 + getAns(Arr, ind + 1, 0, n, dp), -Arr[ind] + getAns(Arr, ind + 1, 1, n, dp));

    if (buy == 1)
        profit = max(0 + getAns(Arr, ind + 1, 1, n, dp), Arr[ind] + getAns(Arr, ind + 1, 0, n, dp));

    return dp[ind][buy] = profit;
}

long getMaximumProfit(long *Arr, int n)
{
    vector<vector<long>> dp(n, vector<long>(2, -1));

    if (n == 0)
        return 0;

    long ans = getAns(Arr, 0, 0, n, dp);
    return ans;
}

// *****************************************************************************************************
// Tabulation :

long getMaximumProfit(long *Arr, int n)
{
    vector<vector<long>> dp(n + 1, vector<long>(2, -1));

    // if (n == 0) : return 0
    dp[n][0] = dp[n][1] = 0;

    long profit;

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            if (buy == 0)
                profit = max(0 + dp[ind + 1][0], -Arr[ind] + dp[ind + 1][1]);

            if (buy == 1)
                profit = max(0 + dp[ind + 1][1], Arr[ind] + dp[ind + 1][0]);

            dp[ind][buy] = profit;
        }
    }

    return dp[0][0];
}
