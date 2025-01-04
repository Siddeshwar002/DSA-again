#include <bits/stdc++.h>
using namespace std;

int maxSumIS(int arr[], int n)
{
    int dp[n];
    int maxSum = 0;

    // Initialize dp array with values from the input array
    for (int i = 0; i < n; ++i)
    {
        dp[i] = arr[i];
    }

    // Find the maximum sum increasing subsequence
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[j] + arr[i], dp[i]);
            }
        }
    }

    // Find the maximum sum in dp array
    for (int i = 0; i < n; ++i)
    {
        if (maxSum < dp[i])
        {
            maxSum = dp[i];
        }
    }

    return maxSum;
}