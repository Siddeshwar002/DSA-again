#include <bits/stdc++.h>
using namespace std;

// Longest Prefix which is also Suffix

vector<int> KMP(string s)
{
    vector<int> Pi(s.length());
    Pi[0] = 0;

    for (int i = 1; i < s.length(); i++)
    {
        int j = Pi[i - 1];

        while (j > 0 && s[i] != s[j])
            j = Pi[j - 1];

        if (s[i] == s[j])
            j++;

        Pi[i] = j;
    }

    return Pi;
}