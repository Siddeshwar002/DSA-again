#include <bits/stdc++.h>
using namespace std;

// ! 545 / 588 testcases passed
// ! Both the code are memoization but still this fails WHY ?

int minSquares(int n)
{
    if (n == 0)
        return 0;

    int ans = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        if (sqrt(i) * sqrt(i) == i)
            ans = min(ans, minSquares(n - i) + 1);
    }
    return ans;
}

int numSquares(int n)
{
    return minSquares(n);
}

// ! ***************************************************************************************
// * Better CODE
// * SMART Coding

class Solution
{
public:
    int minSquares(int n, vector<int> &memo)
    {
        if (n == 0)
        {
            return 0;
        }

        if (memo[n] != -1)
            return memo[n];

        int ans = INT_MAX;
        for (int i = 1; i * i <= n; i++)
        {
            ans = min(ans, minSquares(n - i * i, memo) + 1);
        }

        return memo[n] = ans;
    }
    int numSquares(int n)
    {
        vector<int> memo(n + 1, -1);
        return minSquares(n, memo);
    }
};