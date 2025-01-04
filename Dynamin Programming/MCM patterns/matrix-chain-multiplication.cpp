#include <vector>
#include <iostream>
using namespace std;

/** Memoization code
 *
 * TC - O(N^3)
 */
int f(vector<int> &arr, int i, int j, vector<vector<int>> &dp)
{

    // base condition
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int mini = INT_MAX;

    // partioning loop
    for (int k = i; k <= j - 1; k++)
    {

        int ans = f(arr, i, k, dp) + f(arr, k + 1, j, dp) + arr[i - 1] * arr[k] * arr[j];

        mini = min(mini, ans);
    }

    return dp[i][j] = mini;
}

int matrixMultiplication(vector<int> &arr, int N)
{

    vector<vector<int>> dp(N, vector<int>(N, -1));

    // starting conditions
    int i = 1;
    int j = N - 1;

    return f(arr, i, j, dp);
}

/** Tabulation code 1 :
 *
 * The exact replica of the above memoization converted into tabulation code.
 */

int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N, vector<int>(N, 0));

    /** Memoization :
     *      - i goes from (1, N-1)
     *      - j goes from (i+1, N-1)
     *      - k goes from (i , j-1)
     *
     *  Tabulation :
     *      - i goes from (N-1 , 0)
     *      - j goes from (i+1 , N-1)
     *      - k goes from (i , j-1)
     *
     *      - why not j go from (N-1, i+1)
     *      - this doesn't make sense because
     *      - i lies always to the left of the j
     */
    for (int i = N - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < N; j++)
        {
            int mini = INT_MAX;

            for (int k = i; k <= j - 1; k++)
            {
                int ans = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                mini = min(mini, ans);
            }

            dp[i][j] = mini;
        }
    }

    return dp[1][N - 1];
}

/** Tabulation code 2 :
 *
 * - length increasing method
 *
 */

int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N, vector<int>(N, -1));

    for (int i = 0; i < N; i++)
    {
        dp[i][i] = 0;
    }

    for (int len = 2; len < N; len++)
    {
        for (int i = 1; i < N - len + 1; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[1][N - 1];
}