#include <bits/stdc++.h>
using namespace std;

// ! Memoizatoin code
// * Beats 86%

class Solution
{
public:
    long long Sum(int target, int n, int k, long long sum, int coins, std::vector<std::vector<long long>> &memo)
    {
        if (n == coins)
        {
            if (target == sum)
                return 1;
            return 0;
        }

        if (memo[coins][sum] != -1)
        {
            return memo[coins][sum];
        }

        long long CurSum = 0;
        for (int i = 1; i <= k; i++)
        {
            CurSum += Sum(target, n, k, sum + i, coins + 1, memo);
            CurSum %= (int)1e9 + 7;
        }

        memo[coins][sum] = (CurSum);
        // % (int)1e9+7
        return CurSum;
    }

    int numRollsToTarget(int n, int k, int target)
    {
        std::vector<std::vector<long long>> memo(n + 1, std::vector<long long>(k * n + 1, -1));
        return Sum(target, n, k, 0, 0, memo);
    }
};