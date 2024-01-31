#include <bits/stdc++.h>
using namespace std;

int superEggDropHelper(int k, int n, vector<vector<int>> &memo)
{
    if (n == 0 || n == 1 || k == 1)
    {
        return n;
    }

    if (memo[k][n] != -1)
    {
        return memo[k][n];
    }

    int minAttempts = INT_MAX;

    for (int x = 1; x <= n; ++x)
    {
        int attempts = 1 + max(superEggDropHelper(k - 1, x - 1, memo),
                               superEggDropHelper(k, n - x, memo));
        minAttempts = min(minAttempts, attempts);
    }

    memo[k][n] = minAttempts;
    return minAttempts;
}

int superEggDrop(int k, int n)
{
    vector<vector<int>> memo(k + 1, vector<int>(n + 1, -1));
    return superEggDropHelper(k, n, memo);
}
