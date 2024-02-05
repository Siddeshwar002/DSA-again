// https://leetcode.com/problems/minimum-time-to-revert-word-to-initial-state-ii/

#include <bits/stdc++.h>
using namespace std;

// Application of Z - Function

class Solution
{
public:
    vector<int> z_function(string s)
    {
        int n = s.size();
        vector<int> z(n);
        int l = 0, r = 0;
        for (int i = 1; i < n; i++)
        {
            if (i < r)
            {
                z[i] = min(r - i, z[i - l]);
            }
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            {
                z[i]++;
            }
            if (i + z[i] > r)
            {
                l = i;
                r = i + z[i];
            }
        }
        return z;
    }

    int minimumTimeToInitialState(string word, int k)
    {
        auto z = z_function(word);
        for (int i = k, n = word.size(); i < n; i += k)
            // This condition checks if the Z value at position i equals the length of the remaining substring (n - i).
            // If true, it means there is a repeated pattern starting at position i.
            // In this case, it returns the number of cycles completed (i / k).
            if (z[i] == n - i)
                return i / k;

        // If no repeated pattern is found within the loop,
        // it returns the number of cycles needed to cover the entire string ((word.size() + k - 1) / k).

        // The expression (word.size() + k - 1) / k is a common way to calculate the ceiling of the division result when dividing word.size() by k

        return (word.size() + k - 1) / k;
    }
};