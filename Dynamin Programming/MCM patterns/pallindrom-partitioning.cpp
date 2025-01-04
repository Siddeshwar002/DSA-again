#include <string>
#include <vector>
using namespace std;

/** Memoization code :
 */
bool isPalindrome(int i, int j, string &s)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int minPartitions(int i, int n, string &str, vector<int> &dp)
{
    if (i == n)
        return 0;

    if (dp[i] != -1)
        return dp[i];
    int minCost = INT_MAX;

    for (int j = i; j < n; j++)
    {
        if (isPalindrome(i, j, str))
        {
            int cost = 1 + minPartitions(j + 1, n, str, dp);
            minCost = min(minCost, cost);
        }
    }
    return dp[i] = minCost;
}

int palindromePartitioning(string str)
{
    int n = str.size();
    vector<int> dp(n, -1);

    // why -1 ?
    return minPartitions(0, n, str, dp) - 1;
}

/**Tabulation code :
 *
 */

bool isPalindrome(int i, int j, string &s)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int palindromePartitioning(string str)
{
    int n = str.size();
    vector<int> dp(n + 1, 0);
    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        int minCost = INT_MAX;
        for (int j = i; j < n; j++)
        {
            if (isPalindrome(i, j, str))
            {
                int cost = 1 + dp[j + 1];
                minCost = min(minCost, cost);
            }
        }
        dp[i] = minCost;
    }

    // why -1 ?
    return dp[0] - 1;
}

/** Tabulation : MCM approach */
class Solution
{
public:
    bool IsPallindrom(string str, int i, int j)
    {
        while (i <= j)
        {
            if (str[i] != str[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    int Solve(string str, int start, int end, vector<vector<int>> &dp)
    {
        if (start >= end)
            return 0;

        // if its a pallindrome then no cut is needed - return 0
        if (IsPallindrom(str.substr(start, end - start + 1), start, end))
            return 0;

        if (dp[start][end] != -1)
            return dp[start][end];

        int MinCost = INT_MAX;

        for (int i = start; i <= end - 1; i++)
        {
            int count = 1 + Solve(str, start, i, dp) + Solve(str, i + 1, end, dp);
            MinCost = min(count, MinCost);
        }
        return dp[start][end] = MinCost;
    }

    int minCut(string str)
    {
        vector<vector<int>> dp(str.length() + 1, vector<int>(str.length() + 1, -1));
        return Solve(str, 0, str.length() - 1, dp);
    }
};