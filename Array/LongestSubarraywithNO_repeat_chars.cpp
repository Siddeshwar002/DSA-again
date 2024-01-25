#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> mp;
    int l = 0, r = 0;
    int len = 1;

    if (s.length() == 0)
        return 0;

    while (r < s.length())
    {
        if (mp.find(s[r]) != mp.end() and l <= mp[s[r]] and mp[s[r]] <= r)
        {
            l = mp[s[r]] + 1;
        }
        mp[s[r]] = r;
        len = max(len, r - l + 1);
        r++;
    }

    return len;
}