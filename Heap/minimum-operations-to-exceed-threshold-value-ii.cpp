#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long, vector<long>, greater<> > pq;
        
        for(auto num : nums)
            pq.push(num);
        
        int ans = 0;
        
        while(pq.top() < k){
            long n1 = pq.top();
            pq.pop();
            long n2 = pq.top();
            pq.pop();
            
            long n3 = min(n1,n2)*2 + max(n1,n2);
            pq.push(n3);
            ans++;
        }
        return ans;
        
    }
};