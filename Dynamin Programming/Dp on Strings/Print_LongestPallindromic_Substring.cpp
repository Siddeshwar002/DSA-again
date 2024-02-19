// https : // leetcode.com/problems/longest-palindromic-substring/description/?envType=list&envId=55afh7m7

#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s)
{
    int n = s.length();
    vector<vector<int>> IsPallindrom(n + 1, vector<int>(n + 1, 0));

    vector<int> dp(n + 1, 1);
    // this vector is not necessary

    int idx = 0;
    int maxLen = 1;

    for (int gap = 0; gap < n; gap++)
    {
        for (int l = 0, r = gap; r < n; l++, r++)
        {

            if (l == r)
                IsPallindrom[l][r] = 1;
            else if (gap == 1 and s[l] == s[r])
            {
                IsPallindrom[l][r] = 1;
                dp[l] = 2;
            }
            else if (gap > 1 and s[l] == s[r] && IsPallindrom[l + 1][r - 1])
            {
                dp[l] = r - l + 1;
                IsPallindrom[l][r] = 1;
            }

            if (dp[l] > maxLen)
            {
                idx = l;
                maxLen = dp[l];
            }
        }
    }

    return s.substr(idx, maxLen);
}