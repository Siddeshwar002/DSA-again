#include <string>
#include <vector>
using namespace std;

/**Memoization code :  */
int f(int ind, vector<int> &num, int k, vector<int> &dp)
{
    int n = num.size();

    if (ind == n)
        return 0;

    if (dp[ind] != -1)
        return dp[ind];

    int len = 0;
    int maxi = INT_MIN;
    int maxAns = INT_MIN;

    // j < min(ind + k, n)
    for (int j = ind; j < min(ind + k, n); j++)
    {
        len++;
        maxi = max(maxi, num[j]);
        int sum = len * maxi + f(j + 1, num, k, dp);
        maxAns = max(maxAns, sum);
    }

    return dp[ind] = maxAns;
}

int maxSumAfterPartitioning(vector<int> &num, int k)
{
    int n = num.size();
    vector<int> dp(n, -1);
    return f(0, num, k, dp);
}

/**Tabulation code :  */

int maxSumAfterPartitioning(vector<int> &num, int k)
{
    int n = num.size();

    vector<int> dp(n + 1, 0);

    // Memoization : i goes from (0, n-1)
    // Tabulation  : i goes from (n-1, 0)
    for (int ind = n - 1; ind >= 0; ind--)
    {
        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;

        // j < min(ind + k, n)
        for (int j = ind; j < min(ind + k, n); j++)
        {
            len++;
            maxi = max(maxi, num[j]);
            int sum = len * maxi + dp[j + 1];
            maxAns = max(maxAns, sum);
        }

        dp[ind] = maxAns;
    }

    return dp[0];
}