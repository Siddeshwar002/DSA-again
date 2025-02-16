// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
using namespace std;


// Approach 1 : 
// 1827 / 2558 testcases passed
    int is_this_cost_possible(int mid, vector<pair<int,int>> v, vector<int> time){
        int idx = 0;
        int cost = 0;
        int totTime = 0;

        for(int i = 0; i < v.size(); i++){
            if(cost + v[i].first > mid)
                break;
            
            totTime += time[v[i].second];
            cost += v[i].first;
            idx++;

        }
        
        if(v.size() - idx <= totTime)
            return true;

        return false;
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        
        int lo = 0, hi = (cost.begin(), cost.end(), 0);
        
        vector<pair<int,int>> v;

        for(int i = 0; i < cost.size(); i++)
            v.push_back({cost[i], i});
        

        sort(v.begin(), v.end());

        while(lo <= hi){
            int mid = lo + (hi-lo)/2;

            if(is_this_cost_possible(mid, v, time))
                hi = mid - 1;
            else
                lo = mid + 1;
        }

        return lo;
    }


// Approach 2 : 


int main(){
    vector<int> cost = {26,53,10,24,25,20,63,51};
    vector<int> time = {1,1,1,1,2,2,2,1};
    cout<<paintWalls(cost, time);
    return 0;
}