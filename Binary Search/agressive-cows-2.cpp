
// Approach : Dynamic Programming 
// TC : O(N^2)

// Constraints:
// 2 <= stalls.size() <= 106
// 0 <= stalls[i] <= 108
// 1 <= k <= stalls.size()


class Solution {
public:
    int solve(vector<int> &stalls, int k, int idx, int lastPlaced, int placed) {
        if (placed == k) 
            return INT_MAX;

        if (idx == stalls.size()) 
            return INT_MIN;

        int dist = 0;
        if (lastPlaced != -1) {
            dist = stalls[idx] - lastPlaced;
        }

        int placeCow = solve(stalls, k, idx + 1, stalls[idx], placed + 1);

        int skipCow = solve(stalls, k, idx + 1, lastPlaced, placed);

        if (lastPlaced != -1) 
            placeCow = min(placeCow, dist);
        
        return max(placeCow, skipCow);
    }

    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end()); 
        return solve(stalls, k, 0, -1, 0); 
    }
};
