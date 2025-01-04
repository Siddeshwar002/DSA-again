#include <vector>
#include <iostream>
using namespace std;

/** Memoization code :  */

int findMinimumCost(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int mini = INT_MAX;

    for (int ind = i; ind <= j; ind++)
    {
        int ans = cuts[j + 1] - cuts[i - 1] +
                  findMinimumCost(i, ind - 1, cuts, dp) +
                  findMinimumCost(ind + 1, j, cuts, dp);

        mini = min(mini, ans);
    }

    return dp[i][j] = mini;
}

int minimumCost(int n, int c, vector<int> &cuts)
{
    // add '0' at the beginning
    cuts.insert(cuts.begin(), 0);

    // add 'length' at the end
    cuts.push_back(n);

    // sort the lengths
    sort(cuts.begin(), cuts.end());

    vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));

    // i = 1
    // j = c
    // at index 0 : 0
    // at index c+1 : length
    return findMinimumCost(1, c, cuts, dp);
}

/** Tabulation code :
 *
 *
 */

int minimumCost(int n, int c, vector<int> &cuts)
{
    cuts.insert(cuts.begin(), 0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());

    vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

    for (int i = c; i >= 1; i--)
    {
        for (int j = i; j <= c; j++)
        {
            int mini = INT_MAX;

            for (int ind = i; ind <= j; ind++)
            {
                int ans = cuts[j + 1] - cuts[i - 1] +
                          dp[i][ind - 1] + dp[ind + 1][j];

                mini = min(mini, ans);
            }

            dp[i][j] = mini;
        }
    }

    return dp[1][c];
}
