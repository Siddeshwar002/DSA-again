#include <bits/stdc++.h>
using namespace std;

// ! Recursion
int KShelper(int W, int wt[], int val[], int n, vector<vector<int>> &dp)
{
    if (n < 0 || W <= 0)
        return 0;

    int notTaken = KShelper(W, wt, val, n - 1, dp);
    int taken = INT_MIN;

    if (wt[n] <= W)
    {
        taken = KShelper(W - wt[n], wt, val, n - 1, dp) + val[n];
    }
    return max(notTaken, taken);
}

int knapSack(int W, int wt[], int val[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));
    return KShelper(W, wt, val, n - 1, dp);
}

// ! ***********************************************************************
// ! DP : Memoization

int KShelper2(int W, int wt[], int val[], int n, vector<vector<int>> &dp)
{
    if (n < 0 || W <= 0)
        return 0;

    if (dp[W][n] != -1)
        return dp[W][n];

    int notTaken = KShelper2(W, wt, val, n - 1, dp);
    int taken = INT_MIN;

    if (wt[n] <= W)
    {
        taken = KShelper2(W - wt[n], wt, val, n - 1, dp) + val[n];
    }
    return dp[W][n] = max(notTaken, taken);
}

int knapSack2(int W, int wt[], int val[], int n)
{
    vector<vector<int>> dp(W + 1, vector<int>(n + 1, -1));
    return KShelper2(W, wt, val, n - 1, dp);
}

// ! ***********************************************************************
// ! DP : Tabulation

int knapSack(int W, int wt[], int val[], int n)
{
    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; ++i)
    {
        for (int w = 0; w <= W; ++w)
        {
            // * Base Case
            if (i == 0 || w == 0)
                dp[i][w] = 0;

            // * if possible then check -> max(consider , Not consider)
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);

            // * Not possible so do not consider
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // * Return the answer with max items and max capacity  
    return dp[n][W];
}