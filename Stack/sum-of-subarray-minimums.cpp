#include <vector>
#include <stack>
#include <map>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        map<pair<int, int>, long long> mp; 

        // Iterate through the array and calculate NSE and PSE for each elements
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                int nse = i; 
                int curIdx = st.top();
                int curEle = nums[curIdx];
                st.pop();
                int pse = st.empty() ? -1 : st.top();
                
                int contribution = (nse - curIdx) * (curIdx - pse);
                mp[{curEle, curIdx}] = contribution;
            }
            st.push(i);
        }

        // Handle remaining elements in the stack
        while (!st.empty()) {
            int nse = n; 
            int curIdx = st.top();
            int curEle = nums[curIdx];
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            
            int contribution = (nse - curIdx) * (curIdx - pse);
            mp[{curEle, curIdx}] = contribution;
        }

        // Calculate the final answer
        long long ans = 0;
        const int MOD = 1e9 + 7;
        for (const auto& entry : mp) {
            ans += (entry.first.first * entry.second);
            ans = ans % MOD;
        }

        return ans;
    }
};
