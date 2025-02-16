// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
using namespace std;

// Approcah is Coorect but a few more fine tunnings are required
bool is_Possible(double dis, vector<int>&stations, int k){
  
    for(int i = 1; i < stations.size(); i++){
        if(stations[i] - stations[i-1] > dis){
            if(k == 0)
                return false;
            k--;
        }
    }
    return true;
}
    
double findSmallestMaxDist(vector<int> &stations, int k) {
    double lo = 0, hi = *max_element(stations.begin(), stations.end()) - *min_element(stations.begin(), stations.end());
        
    while(lo <= hi){
        double mid = lo + (hi-lo)/2;
        mid = round(mid*100)/100;
        if(is_Possible(mid , stations, k))
            hi = mid - 0.01;
        else 
            lo = mid + 0.01;
        }
        
    return lo;
        
}

// Approach 2 : 
