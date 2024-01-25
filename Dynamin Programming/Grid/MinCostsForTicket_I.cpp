#include <bits/stdc++.h>
using namespace std;

// ! Brute Force
// ! Recirsive Approach

// ! TLE
// ! 6 / 70 testcases passed
// * LMAO

class Solution
{
public:
    void minCostTicket(int i, int &ans, int cost, int maxDayLimit, vector<int> &days, vector<int> &costs, vector<int> &maxDay)
    {
        if (i == days.size())
        {
            ans = min(cost, ans);
            return;
        }
        for (int j = 0; j < costs.size(); j++)
        {
            if (days[i] < maxDayLimit)
            {
                minCostTicket(i + 1, ans, cost, maxDayLimit, days, costs, maxDay);
            }
            else
                minCostTicket(i + 1, ans, cost + costs[j], days[i] + maxDay[j], days, costs, maxDay);
        }
        return;
    }

    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        vector<int> maxDay = {1, 7, 30};
        int i = 0;
        int cost = 0;
        int ans = INT_MAX;
        int maxDayLimit = 0;

        minCostTicket(i, ans, cost, maxDayLimit, days, costs, maxDay);
        return ans;
    }
};

// ! ************************************************************************************
// * Beats 100% of c++ users
// * Memoization CODE

class Solution
{
public:
    int minCostTicket(int i, vector<int> &days, vector<int> &costs, vector<int> &maxDay, vector<int> &memo)
    {
        if (i == days.size())
        {
            return 0;
        }

        if (memo[i] != -1)
        {
            return memo[i];
        }

        int ans = INT_MAX;

        for (int j = 0; j < costs.size(); j++)
        {
            int k = i;
            while (k < days.size() && days[k] < days[i] + maxDay[j])
            {
                k++;
            }

            ans = min(ans, minCostTicket(k, days, costs, maxDay, memo) + costs[j]);
        }

        memo[i] = ans;
        return ans;
    }

    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        vector<int> maxDay = {1, 7, 30};
        vector<int> memo(days.size(), -1);

        return minCostTicket(0, days, costs, maxDay, memo);
    }
};

// ! ******************************************************************************
// ! Tabulation :

class Solution
{
public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int n = days.back();            // Last day of travel
        vector<int> dp(n + 1, INT_MAX); // dp[i] will store the minimum cost to travel up to day i

        dp[0] = 0; // Base case: No cost to travel on day 0

        for (int i = 1; i <= n; ++i)
        {
            if (find(days.begin(), days.end(), i) != days.end())
            {
                // If the current day is in the list of travel days
                dp[i] = min({
                    dp[max(0, i - 1)] + costs[0], // 1-day pass
                    dp[max(0, i - 7)] + costs[1], // 7-day pass
                    dp[max(0, i - 30)] + costs[2] // 30-day pass
                });
            }
            else
            {
                // If the current day is not in the list of travel days, the cost remains the same as the previous day
                dp[i] = dp[i - 1];
            }
        }

        return dp[n];
    }

    // Example usage:
    int main()
    {
        vector<int> days = {1, 4, 6, 7, 8, 20};
        vector<int> costs = {2, 7, 15};
        int result = mincostTickets(days, costs);
        // Output the result
        return 0;
    }
};