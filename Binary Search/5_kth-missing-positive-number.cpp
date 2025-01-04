#include "../stdc++.h"
using namespace std;

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        vector<int> vec(arr.size(), 0);

        /* This itself makes the whole algorithm O(N) */
        /* Try eliminating this */
        for (int i = 0; i < arr.size(); i++)
        {
            vec[i] = arr[i] - (i + 1);
        }

        int lo = 0;
        int hi = arr.size() - 1;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;

            if (vec[mid] >= k)
                hi = mid - 1;
            else
                lo = mid + 1;
        }

        if (hi >= 0)
            return (arr[hi] + (k - vec[hi]));

        return (k);
    }

    /* Optimized code */
    /* Dont create a vector to store the values */
    /* The whole point of doing Binary search was to make in O(logN) */
    /* Making a vector will make it O(N) - useless */
    int findKthPositive(vector<int> &arr, int k)
    {
        int lo = 0;
        int hi = arr.size() - 1;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;

            // No need to store them in an array
            // Calculate them dynamically
            int missing = arr[mid] - (mid + 1);

            if (missing < k)
                lo = mid + 1;
            else
                hi = mid - 1;
        }

        if (hi >= 0)
        {
            // No need to store them in vec
            int missingUpToHi = arr[hi] - (hi + 1);
            return arr[hi] + (k - missingUpToHi);
        }

        return k;
    }
};
