#include "../stdc++.h"
using namespace std;

class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int lo = 1;
        int hi = *max_element(piles.begin(), piles.end());
        int res = INT_MAX;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            long ans = 0;

            for (int x : piles)
            {
                // Optimization needed here
                ans += ceil(double(x) / double(mid));
            }

            if (ans <= h)
            {
                res = min(res, mid);
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return res;
    }

    int minEatingSpeed_2(vector<int> &piles, int h)
    {
        int lo = 1;
        int hi = *max_element(piles.begin(), piles.end());

        // The answer shuold be assigned to this
        int res = hi;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            long hours = 0;

            for (int x : piles)
            {
                // Avoids floating point operations
                hours += (x + mid - 1) / mid;
            }

            if (hours <= h)
            {
                res = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return res;
    }
};