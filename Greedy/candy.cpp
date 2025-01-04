#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> ans (ratings.size() , -1);
        map<int,vector<int>>mp;

        for(int i = 0 ; i < ratings.size(); i++)
            mp[ratings[i]].push_back(i);

        if(ratings.size() == 1)return 1;
        
        for(auto x : mp){
            for(int i : x.second){
                if(i == 0)
                    ans[i] = max(0 , ans[1]) + 1;
                
                else if(i == ratings.size()-1){
                    if(ratings[i] == ratings[i-1])
                        ans[i] = 1;
                    else
                        ans[i] = max(0 , ans[i-1]) + 1;
                }
                else{
                    if(ratings[i] == ratings[i-1]){
                        ans[i] = max(0, ans[i+1]) + 1;
                    }

                    else
                        ans[i] = max(0, max(ans[i-1] , ans[i+1])) + 1;
                }
            }
        }

        int res = 0;
        for(auto x : ans){
            if(x > 0)res += x;
            cout<<x<<" ";
        }
        return res;
    }
};