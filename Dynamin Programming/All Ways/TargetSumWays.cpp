#include <bits/stdc++.h>
using namespace std;

// Recursive code :

class Solution
{
public:
    int TargetSum(vector<int> &nums, int target, int sum, int idx)
    {
        if (idx == nums.size())
        {
            if (sum == target)
                return 1;
            return 0;
        }

        int consider = TargetSum(nums, target, sum + nums[idx], idx + 1);
        int notConsider = TargetSum(nums, target, sum - nums[idx], idx + 1);

        return (consider + notConsider);
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        return TargetSum(nums, target, 0, 0);
    }
};

// ********************************************************************************
// Memoization with MAP
// sum can be negative values too
// If sum = -5; dp[idx][sum] ?

class Solution
{
public:
    int TargetSumMemo(vector<int> &nums, int target, int sum, int idx, unordered_map<string, int> &memo)
    {
        string key = to_string(idx) + "_" + to_string(sum);

        if (memo.find(key) != memo.end())
        {
            return memo[key];
        }

        if (idx == nums.size())
        {
            memo[key] = (sum == target) ? 1 : 0;
            return memo[key];
        }

        int consider = TargetSumMemo(nums, target, sum + nums[idx], idx + 1, memo);
        int notConsider = TargetSumMemo(nums, target, sum - nums[idx], idx + 1, memo);

        memo[key] = consider + notConsider;

        return memo[key];
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        unordered_map<string, int> memo;
        return TargetSumMemo(nums, target, 0, 0, memo);
    }
};

// ! ********************************************************************************
// ! Approach 3:

// * Solving by using the concept of subset and diff
// * Set -> divided into Subset1 and Subset2
// * Subset --> Split into --> Sub1 and Sub2 --> calculate Difference(Sub1, Sub2)
// * Make Diff (Sub1, Sub2) == Target
