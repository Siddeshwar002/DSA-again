// https://leetcode.com/problems/house-robber/description/?envType=list&envId=55af7bu7

#include <bits/stdc++.h>
using namespace std;

// memoization
class Solution
{
public:
    int solve(vector<int> &nums, int idx, vector<int> &memo)
    {
        if (idx >= nums.size())
            return 0;

        if (memo[idx] != -1)
        {
            return memo[idx];
        }

        int rob = solve(nums, idx + 2, memo) + nums[idx];
        int skip = solve(nums, idx + 1, memo);

        memo[idx] = max(rob, skip);

        return memo[idx];
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> memo(n, -1);
        return solve(nums, 0, memo);
    }
};

// ****************************************************************************************************
// Tabulation

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 2, 0);

        for (int idx = n - 1; idx >= 0; idx--)
        {

            int rob = dp[idx + 2] + nums[idx];
            int skip = dp[idx + 1];

            dp[idx] = max(rob, skip);
        }
        return dp[0];
    }
};