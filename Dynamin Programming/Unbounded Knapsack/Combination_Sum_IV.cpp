#include <bits/stdc++.h>
using namespace std;

// Given an array of distinct integers nums and a target integer target,
// return the number of possible combinations that add up to target.
// The test cases are generated so that the answer can fit in a 32-bit integer.

// ! Memoized using
// * map<int,int> memo

class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        unordered_map<int, int> memo;
        return allWays(nums, target, memo);
    }

private:
    int allWays(vector<int> &nums, int target, unordered_map<int, int> &memo)
    {
        if (memo.find(target) != memo.end())
        {
            return memo[target];
        }

        if (target == 0)
        {
            return 1;
        }

        int ways = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (target >= nums[i])
            {
                ways += allWays(nums, target - nums[i], memo);
            }
        }

        memo[target] = ways;

        return ways;
    }
};
