#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // The farthest point I can reach from the place where I am standing
        int maxIdx = 0;

        // Example : 
        // in the below loop lets say for i = 2;
        // means standing at index = 2, the farthest I can jump from here is what ? 
        // I calculate it and update the maxIdx
        // At any iteration i, if my current position which is 'i' is that's greater that the maxIdx 
        // which is the maximum position that I can reach.
        // then that means i dont have enogh jumps the reach the current position.
        // If I am unable t reach the current position 
        // how will I go ahead ? 

        // Comprehension : 
        // If the array always contains positive integers then 
        // We will always be able to reach the end goal
        // Only if the array has 0's then we need this solution

        for(int i = 0; i < nums.size(); i++){
            if(i > maxIdx) return false;
            maxIdx = max(maxIdx , i + nums[i]);
        } 
        return true;
    }
};