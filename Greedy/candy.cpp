#include <bits/stdc++.h>
using namespace std;

// Approach 1 : 

// Using map store indices of the elements
// traversing the entire map and assigning cholates to the smallest members first
// then comparing the assigned chocolates for the neighbours and taking the decision for the members coming later

// Edges case handling : 
//      For 0th and n-1th member
//      is the elements are equal and not equal

// TC : O(2N)
// SC : O(N)

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

// Approach 2 : 
// Slope methtod

// TC : O(N)
// SC : O(N)

class Solution 
{
public:
    int candy(vector<int>& ratings) 
    {
        int n=ratings.size();
        int i=1;
        int sum=1;

        while(i<n)
        {
            if(ratings[i]==ratings[i-1])
            {
                sum+=1;
                i++;
                continue;
            }

            int peak=1;
            while(i<n && ratings[i]>ratings[i-1])
            {
               peak+=1;
               sum+=peak;
               i++;
            }
            
            int down=1;
            while(i<n && ratings[i]<ratings[i-1])
            {
                sum+=down;
                down+=1;
                i++;
            }
            
            if(down>peak)
            {
                sum=sum+(down-peak);
            }
        }
        return sum;
    }
};