#include <bits/stdc++.h>
using namespace std;

// TODO : SAME TIME COMPLEXITY = O(M*N)

// ! DP : memoization
int editDistanceUtil(string &S1, string &S2, int i, int j, vector<vector<int>> &dp)
{
    // Base cases
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (S1[i] == S2[j])
        return dp[i][j] = 0 + editDistanceUtil(S1, S2, i - 1, j - 1, dp);

    else
        return dp[i][j] = 1 + min(editDistanceUtil(S1, S2, i - 1, j - 1, dp),
                                  min(editDistanceUtil(S1, S2, i - 1, j, dp),
                                      editDistanceUtil(S1, S2, i, j - 1, dp)));
}

int minDistance(string &S1, string &S2)
{
    int n = S1.size();
    int m = S2.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    return editDistanceUtil(S1, S2, n - 1, m - 1, dp);
}

// ! DP : Tabulation
int minDistance2(string &S1, string &S2)
{

    int n = S1.size();
    int m = S2.size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    // Base Case = Initialize the first row and column
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = j;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (S1[i - 1] == S2[j - 1])
            {
                // If the characters match, no additional cost
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                // Minimum of three choices:
                // 1. Replace the character at S1[i-1] with S2[j-1]
                // 2. Delete the character at S1[i-1]
                // 3. Insert the character at S2[j-1] into S1
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            }
        }
    }

    // The value at dp[n][m] contains the edit distance
    return dp[n][m];
}