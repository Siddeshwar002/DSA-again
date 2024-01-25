#include <bits/stdc++.h>
using namespace std;

int knapsackUtil(vector<int> &wt, vector<int> &val, int ind, int W, vector<vector<int>> &dp)
{
    // Base case: If there are no items left or the knapsack has no capacity, return 0
    if (ind == 0 || W == 0)
    {
        return 0;
    }

    if (dp[ind][W] != -1)
    {
        return dp[ind][W];
    }

    int notTaken = knapsackUtil(wt, val, ind - 1, W, dp);
    int taken = 0;

    if (wt[ind] <= W)
    {
        taken = val[ind] + knapsackUtil(wt, val, ind - 1, W - wt[ind], dp);
    }

    return dp[ind][W] = max(notTaken, taken);
}

// ! REFER BELOW
int knapsack(vector<int> &wt, vector<int> &val, int n, int W)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    // Base condition: Fill in the first row for the weight of the first item
    for (int i = wt[0]; i <= W; i++)
    {
        dp[0][i] = val[0];
    }

    for (int ind = 1; ind < n; ind++)
    {
        for (int w = 0; w <= W; w++)
        {
            int notTaken = dp[ind - 1][w];
            int taken = INT_MIN;

            if (wt[ind] <= w)
            {
                taken = val[ind] + dp[ind - 1][w - wt[ind]];
            }

            dp[ind][w] = max(notTaken, taken);
        }
    }

    return dp[n - 1][W];
}

// ! REFER THIS
int knapsackTabulation(vector<int> &wt, vector<int> &val, int W)
{
    int n = wt.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i)
    {
        for (int w = 1; w <= W; ++w)
        {
            if (wt[i - 1] <= w)
            {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}