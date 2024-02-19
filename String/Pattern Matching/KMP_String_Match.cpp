#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; ++i)
#define print(x) std::cout << (x) << std::endl

// KMP String matching algotithm
// Uses 'Pi' Function to match

vector<int> KMP(string s, string p)
{
    s = p + '#' + s;
    cout << "S ";
    cout << s << endl;
    vector<int> Pi(s.length());
    vector<int> ans;
    Pi[0] = 0;

    for (int i = 1; i < s.length(); i++)
    {
        int j = Pi[i - 1];

        while (j > 0 && s[i] != s[j])
            j = Pi[j - 1];

        if (s[i] == s[j])
            j++;

        Pi[i] = j;
        if (j == p.length())
            ans.push_back(i - 2 * p.length());
    }

    return ans;
}