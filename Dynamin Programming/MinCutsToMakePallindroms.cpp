#include <bits/stdc++.h>
using namespace std;

bool IsPallindrom(string str, int start, int end)
{
    while (start <= end)
    {
        if (str[start++] != str[end--])
            return false;
    }
    return true;
}

int minimumCuts(string s, int idx)
{
    if (idx == s.length())
        return -1;

    int minCut = INT_MAX;

    for (int i = idx; i < s.length(); i++)
    {
        int cut = 0;

        if (IsPallindrom(s, idx, i))
        {
            cut = 1 + minimumCuts(s, i + 1);
            minCut = min(minCut, cut);
        }
    }
    return minCut;
}

int minCut(string s)
{
    return minimumCuts(s, 0);
}

// ! *******************************************************************************

// ! DP : Memoization
// * 32 / 37 testcases passed

bool IsPallindrom(string str, int start, int end)
{
    while (start <= end)
    {
        if (str[start++] != str[end--])
            return false;
    }
    return true;
}

int minimumCuts2(string s, int idx, vector<int> &dp)
{
    if (idx == s.length())
        return -1;

    if (dp[idx] != -1)
        return dp[idx];

    int minCut = INT_MAX;

    for (int i = idx; i < s.length(); i++)
    {
        int cut = 0;

        if (IsPallindrom(s, idx, i))
        {
            cut = 1 + minimumCuts2(s, i + 1, dp);
            minCut = min(minCut, cut);
        }
    }
    return dp[idx] = minCut;
}

int minCut2(string s)
{
    vector<int> dp(s.length(), -1);
    return minimumCuts2(s, 0, dp);
}

// ! *******************************************************************************

int main()
{
    cout << minCut("aab");
}