#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, f, a, b;
    cin >> n >> f >> a >> b;
    long long m[n];

    for (long long i = 0; i < n; i++)
    {
        cin >> m[i];
    }

    long long st = 0;

    for (long long i = 0; i < n; i++)
    {
        if ((m[i] - st) * a > b)
            f = f - b;
        else
            f = f - (m[i] - st) * a;

        st = m[i];

        if (f <= 0)
        {
            cout << "NO" << endl;
            break;
        }
    }

    if (f > 0)
        cout << "YES" << endl;
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
