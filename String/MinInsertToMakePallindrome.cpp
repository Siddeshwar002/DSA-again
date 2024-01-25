#include <bits/stdc++.h>
using namespace std;

// * Recursive Approach
// * Works but

// ! Memory Limit Exceeded
// TODO : Use DP

int MinInsertions(string s, int l, int r, int len)
{
    if (l >= len or r < 0)
        return 0;

    if (l > r)
        return 0;

    if (s[l] == s[r])
        return MinInsertions(s, l + 1, r - 1, len);

    else
    {
        return min(MinInsertions(s, l + 1, r, len) + 1, MinInsertions(s, l, r - 1, len) + 1);
    }
}

int main()
{
    string s = "mbadm";
    int l = 0;
    int r = s.length() - 1;

    cout << "Ans : " << MinInsertions(s, l, r, s.length());
}