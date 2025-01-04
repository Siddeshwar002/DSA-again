#include "../stdc++.h"
using namespace std;

class Solution
{
public:
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int lo = *min_element(bloomDay.begin(), bloomDay.end());
        int hi = *max_element(bloomDay.begin(), bloomDay.end());
        int res = INT_MAX;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            int cnt = 0;
            int boquet = 0;

            for (int x : bloomDay)
            {
                if (x <= mid)
                {
                    cnt++;
                }
                else
                    cnt = 0;

                if (cnt == k)
                {
                    cnt = 0;
                    boquet++;
                }
            }

            if (boquet >= m)
            {
                res = min(res, mid);
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }

        if (res == INT_MAX)
            return -1;
        return res;
    }
};