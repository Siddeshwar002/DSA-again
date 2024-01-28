#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; ++i)

void solve()
{
    int n, k , l;
    cin >> n >> k >>l;

    string s;
    cin >> s;

    map<char, int> mp;

    for (auto ch : s)
    {
        mp[ch]++;
    }
    bool found = 0;
    for (auto x : mp)
    {
        if (x.second < n)
        {
            string ans(x.second + 1, x.first);
            cout << "No" << endl;
            cout << ans << endl;
            found = 1;
            break;
        }
    }
    if (!found)
        cout << "Yes" << endl;
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
