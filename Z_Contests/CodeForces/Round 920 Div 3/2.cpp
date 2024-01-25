#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    string s1, s2;
    cin >> s1 >> s2;

    int a = 0, r = 0;

    for (int i = 0; i < n; i++)
    {
        if (s1[i] == '1' && s2[i] == '0')
            r++;
        else if (s1[i] == '0' && s2[i] == '1')
            a++;
    }

    cout << max(a, r) << endl;
}

int main()
{
    ios::sync_with_stdio();
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
