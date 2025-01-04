#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int r = 0, l = 0, minLen = INT_MAX, cnt = 0;
        int idx = -1;
        map<char, int> mp;

        // Populate the map with characters in `t`
        for (char c : t) {
            mp[c]++;
        }

        int required = t.length();

        while (r < s.size()) {

                mp[s[r]]--;
                if (mp[s[r]] >= 0) {
                    cnt++;
                }

            while (cnt == required) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    idx = l;
                }

                mp[s[l]]++;
                if (mp[s[l]] > 0)
                    cnt--;
            
                l++;
            }
            r++;
        }

        if (idx == -1) return "";

        return s.substr(idx, minLen);
    }
};
