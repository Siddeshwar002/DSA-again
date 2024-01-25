#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; ++i)

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    int idx = -1;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] > s[i + 1])
        {
            idx = i;
            break;
        }
    }

    if (idx == -1)
        s.erase(n - 1, 1);
    else
        s.erase(idx, 1);

    cout << s << endl;
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
