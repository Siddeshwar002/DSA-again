#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; ++i)

void solve()
{
    long long h, x, y1, y2, k;
    cin >> h >> x >> y1 >> y2 >> k;

    long long h1 = 0;
    if (h % x != 0)
    {
        h1 = int(h / x) + 1;
    }
    else
        h1 = (int)h / x;

    long long h2 = 0, h3 = 0;

    if (h % y1 != 0)
        h2 = (int)h / y1 + 1;
    else
        h2 = (int)h / y1;

    long long hn = 0;
    if (k < h2)
    {
        hn = h - y1 * (k);

        if (hn % y2 != 0)
            h3 = int(hn / y2) + 1;
        else
            h3 = int(hn / y2);

        if (h1 <= k + h3)
        {
            cout << h1 << endl;
            return;
        }
        else
        {
            cout << k + h3 << endl;
            return;
        }
    }
    else if (h1 <= h2)
    {
        cout << h1 << endl;
        return;
    }
    else
    {
        cout << h2 << endl;
    }
    return;
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
