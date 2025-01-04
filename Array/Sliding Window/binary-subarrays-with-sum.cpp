#include <bits/stdc++.h>
using namespace std;

// Correct Answer : 
// why did your other solutions fail ? 
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<int,int> mp;
        int prefixSum = 0;
        int ans = 0;
        for(auto n : nums){
            prefixSum += n;
            if(prefixSum == goal)ans++;
            if(mp[prefixSum - goal])ans += mp[prefixSum - goal];    
            // Doing it at the end has a major role to play       
            mp[prefixSum]++;
        }
        return ans;

    }
};

// Wrong Answer : 
// nums =
// [0,0,0,0,0,0,1,0,0,0]
// goal =
// 0

// Use Testcase
// Output
// 31
// Expected
// 27
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<int,int> mp;
        int prefixSum = 0;
        int ans = 0;
        for(auto n : nums){
            prefixSum += n;
            mp[prefixSum]++;
            if(goal != 0 and prefixSum == goal)ans++;
            if(mp[prefixSum - goal])ans += mp[prefixSum - goal];
        }
        return ans;

    }
};

// Wrong Answer : 
// nums =
// [0,1,1,1,1]
// goal =
// 3

// Use Testcase
// Output
// 2
// Expected
// 3
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<int,int> mp;
        int prefixSum = 0;
        int ans = 0;
        for(auto n : nums){
            prefixSum += n;
            mp[prefixSum]++;
            if(mp[prefixSum - goal])ans += mp[prefixSum - goal];
            else if(prefixSum == goal)ans++;
             
        }
        return ans;

    }
};

// wrong Answer :
// nums = [0,0,0,0,1] 
// goal =
// 2

// Use Testcase
// Output
// 1
// Expected
// 0
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<int,int> mp;
        int prefixSum = 0;
        int ans = 0;
        for(auto n : nums){
            prefixSum += n;
            mp[prefixSum]++;
            if(mp[prefixSum] == goal)ans++;
            if(mp[prefixSum - goal])ans += mp[prefixSum - goal];
        }
        return ans;

    }
};