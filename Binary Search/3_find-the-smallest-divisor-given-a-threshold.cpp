#include "../stdc++.h"
using namespace std;

class Solution
{
public:
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int lo = 1;
        int hi = *max_element(nums.begin(), nums.end());
        int res = hi;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            int ans = 0;

            for (int x : nums)
            {
                ans += (x + (mid - 1)) / mid;
            }

            if (ans <= threshold)
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