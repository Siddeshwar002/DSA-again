#include <vector>
#include <stack>
#include <map>
using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
                stack<int> st;
        int n = nums.size();
        map<pair<int, int>, long long> mp; 
        map<pair<int, int>, long long> mp2; 

        // NEXT SMALLER ELEMENT
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

        while (!st.empty()) {
            int nse = n; 
            int curIdx = st.top();
            int curEle = nums[curIdx];
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            
            int contribution = (nse - curIdx) * (curIdx - pse);
            mp[{curEle, curIdx}] = contribution;
        }

        long long minSum = 0;
        const int MOD = 1e9 + 7;
        for (const auto& entry : mp) {
            minSum += (entry.first.first * entry.second);
        }

        // NEXT GREATER ELEMENT
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                int nse = i; 
                int curIdx = st.top();
                int curEle = nums[curIdx];
                st.pop();
                int pse = st.empty() ? -1 : st.top();
                
                int contribution = (nse - curIdx) * (curIdx - pse);
                mp2[{curEle, curIdx}] = contribution;
            }
            st.push(i);
        }

        while (!st.empty()) {
            int nse = n; 
            int curIdx = st.top();
            int curEle = nums[curIdx];
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            
            int contribution = (nse - curIdx) * (curIdx - pse);
            mp2[{curEle, curIdx}] = contribution;
        }

        long long maxSum = 0;
        for (const auto& entry : mp2) {
            maxSum += (entry.first.first * entry.second);
        }

        // ∑ Largest in all subarrays - ∑ Smallest in all the sub arrays
        return maxSum - minSum;
    }
};