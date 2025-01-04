#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        map<int,int> mp;
        int cnt = 0;
        int ans = 0;

        for(auto n : nums){
            if(n%2 == 1)
                cnt++;
            
            if(cnt == k)ans++;
            if(mp[cnt-k])ans += mp[cnt-k];
            mp[cnt]++;
        }
        return ans;
    }
};