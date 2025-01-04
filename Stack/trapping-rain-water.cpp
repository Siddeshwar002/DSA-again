#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> leftMax(n , 0);
        vector<int> RightMax(n , 0);

        // prefix array
        leftMax[0] = INT_MIN;
        for(int i = 1 ; i < n ; i++){
            leftMax[i] = max(leftMax[i-1] , height[i-1]);
        }

        // suffix array
        RightMax[n-1] = INT_MIN;
        for(int i = n-2 ; i >=0 ;i--){
            RightMax[i] = max(RightMax[i+1] , height[i+1]);
        }

        // take the minimum of both the (leftMax , rightMax) - current_height
        int Tot = 0;
        for(int i = 1 ; i < n-1 ;i++){
            if(min(leftMax[i] , RightMax[i]) > height[i])
                Tot+= min(leftMax[i] , RightMax[i]) - height[i];
        }
        return Tot;
    }
};