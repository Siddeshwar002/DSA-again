#include <unordered_map>
#include <vector>
#include <cmath>
using namespace std;

// Approach 1 : 
// 533 / 557 testcases passed

class Solution {
public:
    vector<int> res;
    unordered_map<string, long long> memo; // Memoization table
    const double EPSILON = 1e-9;  // Define a small tolerance for floating-point comparison
    
    long long solve(vector<int>& nums, int idx, int cnt, bool isMultiply , double ans){
        // Create a unique key for the current state
        string key = to_string(idx) + "-" + to_string(cnt) + "-" + to_string(isMultiply) + "-" + to_string(ans);
        
        // Check if the result for this state is already computed
        if(memo.find(key) != memo.end()) {
            return memo[key];
        }

        if(cnt == 4){
            // Use a tolerance to check for equality with 1.0
            if(fabs(ans - 1.0) < EPSILON){
                return 1;
            }
            return 0;
        }
        
        if(idx >= nums.size()){
            return 0;
        }

        double cur_ans = ans;

        if(isMultiply){
            ans = ans * nums[idx];
        } else {
            ans = ans / nums[idx];
        }
        
        long long consider = 0 , notConsider = 0;
        res.push_back(nums[idx]);
        consider += solve(nums, idx+2, cnt+1, !isMultiply, ans);
        res.pop_back();
        notConsider += solve(nums, idx+1, cnt, isMultiply , cur_ans);

        // Store the result in the memo table
        memo[key] = consider + notConsider;
        
        return memo[key];
    }
    
    long long numberOfSubsequences(vector<int>& nums) {
        return solve(nums, 0, 0, true, 1);
    }
};
