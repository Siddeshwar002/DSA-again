#include <iostream>
#include <vector>
using namespace std;

// Approach 1 : 
// Brute Force : 
// it creates array for all the bags on the numberline, whose size is 1e9
// Problems : 
//      - MLE : using this much amount of memory leads to MLE.
//      - TLE : Performing slinding window on this much big data give TLE.

// Alternative : 
//      coins.length is 1e5
//      the solution should be based on that 
class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {

        // sort
        sort(coins.begin(), coins.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] != b[0])
                     return a[0] < b[0];
                 if (a[1] != b[1])
                     return a[1] < b[1];
                 return a[2] < b[2];
             });

        cout<<"j "<<coins[coins.size()-1][1]<<endl;
        cout<<"i "<<coins[0][0]<<endl;
        
        long long n = coins[coins.size()-1][1] - coins[0][0] + 1;
        vector<long long> arr(n, 0);

        for(auto row : coins){
            int i = row[0];
            int j = row[1]; 
            int c = row[2];

            cout<<"coin " << c<<endl;

            for(int k = i; k<= j; k++)
                arr[k-coins[0][0]] = c;
        }

        for(int i = 0 ; i < n ; i++)
            cout<<arr[i]<<" ";

        long long ans = INT_MIN, res = 0;

      

        for(int i = 0 ; i < n; i++){
            if(i >= k){
                ans = max(ans , res);
                res -= arr[i-k];
            }
            res += arr[i];
        }

        if(k > n){
            return res;
        }

        return ans;
    }
};

// Apprach 2 : 
// Use Sliding window on the coins
// HARD

