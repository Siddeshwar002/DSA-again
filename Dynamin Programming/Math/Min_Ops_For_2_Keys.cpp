#include <bits/stdc++.h>
using namespace std;

// ! Brute Force
// ! Recirsive Approach
// * Beats 50% of users

class Solution
{
public:
    int minOps(int len, int prev, int n)
    {
        if (n == 1)
            return 0;
        if (len == n)
            return 0;

        if (len > n)
            return INT_MAX;

        int l = INT_MAX, r = INT_MAX;

        if (prev != 0)
        {
            l = minOps(len + prev, prev, n);
        }
        if (l != INT_MAX)
            l += 1;

        r = minOps(len * 2, len, n);
        if (r != INT_MAX)
            r += 2;

        return min(l, r);
    }

    int minSteps(int n)
    {
        return minOps(1, 0, n);
    }
};

// ! ************************************************************************************
