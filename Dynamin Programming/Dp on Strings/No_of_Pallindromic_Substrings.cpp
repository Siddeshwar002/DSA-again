// https : // leetcode.com/problems/palindromic-substrings/description/?envType=list&envId=55afh7m7

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSubstrings(string s)
    {
        int n = s.length();
        vector<vector<int>> isPallindrome(n, vector<int>(n, 0));

        int ans = n;

        for (int gap = 0; gap < n; gap++)
        {
            for (int l = 0, r = gap; r < n; l++, r++)
            {

                if (gap == 0)
                    isPallindrome[l][r] = 1;
                else if (gap == 1 && s[l] == s[r])
                {
                    isPallindrome[l][r] = 1;
                    ans++;
                }
                else if (s[l] == s[r] && isPallindrome[l + 1][r - 1])
                {
                    isPallindrome[l][r] = 1;
                    ans++;
                }
            }
        }
        return ans;
    }
};