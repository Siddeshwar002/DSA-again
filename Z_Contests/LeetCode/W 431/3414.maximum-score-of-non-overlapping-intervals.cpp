#include <iostream>
#include <vector>
using namespace std;

// Custom hash function for vector<int>
struct VectorHash {
    size_t operator()(const vector<int>& v) const {
        size_t hash = 0;
        for (int num : v) {
            hash ^= hash * 31 + std::hash<int>{}(num);
        }
        return hash;
    }
};

class Solution {
public:
    void solve(int lastEle, int idx, int cnt, long long& ans, long long& res,
               vector<vector<int>>& intervals, vector<int>& ds,
               vector<int>& dsRes,
               unordered_map<vector<int>, int, VectorHash>& mp) {
        if (cnt == 0 || idx == intervals.size()) {
            if (ans > res) {
                res = ans;
                dsRes = ds;
                return;
            } else
                return;
        }

        if (intervals[idx][0] > lastEle) {
            ans += intervals[idx][2];
            ds.push_back(
                mp[intervals[idx]]); // Add the original index using the map
            solve(intervals[idx][1], idx + 1, cnt - 1, ans, res, intervals, ds,
                  dsRes, mp);

            ans -= intervals[idx][2];
            ds.pop_back();
        }

        solve(lastEle, idx + 1, cnt, ans, res, intervals, ds, dsRes, mp);
        return;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        // Create a map to store original indices
        unordered_map<vector<int>, int, VectorHash> mp;
        
        for (int i = 0; i < intervals.size(); ++i) {
            if(mp.find(intervals[i]) == mp.end())
            mp[intervals[i]] = i;
        }

        // Sort intervals based on start time, end time, and weight
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });
        // Debug: Print intervals after sorting
        for (const auto& interval : intervals) {
            for (const auto& num : interval) {
                cout << num << " ";
            }
            cout << endl;
        }

        long long ans = 0;
        long long res = INT_MIN;
        vector<int> ds, dsRes;
        solve(-1, 0, 4, ans, res, intervals, ds, dsRes, mp);
        sort(dsRes.begin(), dsRes.end());
        return dsRes;
    }
};



int main(){
    // vector<vector<int>> intervals = {{1,3,2},{4,5,2},{1,5,5},{6,9,3},{6,7,1},{8,9,1}};
    vector<vector<int>> intervals = {{1, 1, 1000000000}, {1, 1, 1000000000}, {1, 1, 1000000000}, {1, 1, 1000000000}};
    Solution s;
    vector<int> res = s.maximumWeight(intervals);
    cout<<endl;
    for(auto r : res)
        cout<< r<<" ";
    cout<<endl;

    return 0;

}

// 1 3 2 
// 1 5 5 
// 4 5 2 
// 6 7 1 
// 6 9 3 
// 8 9 1 

// 0 3