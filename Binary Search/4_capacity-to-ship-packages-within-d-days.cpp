#include "../stdc++.h"
using namespace std;

class Solution
{
public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        int lo = *max_element(weights.begin(), weights.end());
        int hi = 0;
        int res = INT_MAX;

        for (auto x : weights)
        {
            hi += x;
        }

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            int D = 0;
            int cur_weight = 0;

            for (auto x : weights)
            {

                if (cur_weight + x > mid)
                {
                    D++;
                    cur_weight = x;
                    // Intresting code here >>>
                    // cur_weight = 0 ? cur_weight = x
                }
                else
                    cur_weight += x;
            }

            // Why again D++ here ?
            // is it to consider the last bunch of boxes ?
            D++;

            if (D <= days)
            {
                res = min(res, mid);
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        return res;
    }
};