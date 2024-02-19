#include <bits/stdc++.h>
using namespace std;

// this is the application of Longest Increasing Subsequence
// Super problem

class Solution
{
public:
    int maxSelectedElements(vector<int> &nums)
    {
        vector<int> dp(1e6 + 1, 0);
        sort(nums.begin(), nums.end());

        for (auto num : nums)
        {
            dp[num + 1] = dp[num] + 1;
            dp[num] = dp[num - 1] + 1;
        }

        int ans = 1;
        for (auto ele : dp)
            ans = max(ans, ele);

        return ans;
    }
};