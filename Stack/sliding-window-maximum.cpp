#include "stack"
#include "vector"
using namespace std;

// Approach 1 : 
// Using Prioity Queue
// TC : N(log N)
// SC : O(N)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> qp;
        vector<int> ans;

        for(int i = 0; i <= nums.size(); i++){
            if(i >=k) {
                while(!qp.empty() && qp.top().second < i-k )
                    qp.pop();

                ans.push_back(qp.top().first);
                
            }
            if(i < nums.size())
            qp.push({nums[i] , i});

        }
        return ans;
    }
};


// Approach 2 : 
// Dequeue
// maintinaing a Max Queue 
// TC : O(N)
// SC : O(N)
