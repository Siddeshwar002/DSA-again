#include <bits/stdc++.h>
using namespace std;

// ! Dynmic Programming
// ! Binary Search

int maxProfit(vector<vector<int>> &nums, int idx, vector<int> &memo)
{
    if (idx >= nums.size())
        return 0;
    if (memo[idx] != -1)
        return memo[idx];

    int lo = 0, hi = nums.size() - 1;
    // int newJobTime = nums.size() + 1;

    while (lo <= hi)
    {
        int mid = (lo + hi) >> 1;
        if (nums[mid][0] >= nums[idx][1])
        {
            // newJobTime = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }

    int notConsider = maxProfit(nums, idx + 1, memo);
    int consider = nums[idx][2] + maxProfit(nums, lo, memo);

    memo[idx] = max(consider, notConsider);
    return memo[idx];
}

int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
{
    int N = startTime.size();
    vector<vector<int>> nums(N);
    for (int i = 0; i < N; ++i)
    {
        nums[i] = {startTime[i], endTime[i], profit[i]};
    }
    sort(nums.begin(), nums.end());

    vector<int> memo(N, -1);
    return maxProfit(nums, 0, memo);
}