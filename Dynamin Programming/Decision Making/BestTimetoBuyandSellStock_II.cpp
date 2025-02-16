// https : // leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

// #include <bits/stdc++.h>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
using namespace std;

// Approach 1 : Stack
// Monotonic Stack
// My own code : Beats 100% of the solutions
// TC : O(N)
// SC : O(N)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int i = 0;
        stack<int> st;
        
        // awesome way to handle the sorted arrays [1,2,3,4,5]
        prices.push_back(-1);

        while(i < prices.size()){
            if(!st.empty() && st.top() > prices[i]){
                int cur = st.top();
                st.pop();
                int ans = 0;

                while(!st.empty()){
                    ans = max(ans , cur - st.top());
                    st.pop();
                }
                res += ans;
            }
            st.push(prices[i]);
            i++;
        }

        return res;
    }
};

// Approch 2 : Mathematics ∑
// One-pass solutino
// Using Math 
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

// Approach 3 : 
// Memoization :
// You can either buy or skip
// You can eihter sell or skip
// you maintain a flag to change status if you have bought it or if you have sold it

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

// Apprach 4 :
// Same code writting in Tabulation :

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
