#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int> &nums, int idx, vector<int> &dp){
        if(idx >= nums.size()-1)return 0;

        if(dp[idx] != -1)return dp[idx];

        int mini = INT_MAX;
        for(int i = 1; i<= nums[idx]; i++){
            int curAns = solve(nums, idx + i, dp);
            mini = min(curAns , mini);
        }
        return dp[idx] = (mini == INT_MAX ? INT_MAX : mini + 1);
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size() , -1);
        return solve(nums, 0 , dp);
    }
};