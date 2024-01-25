#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    int a[n], b[m];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < m; i++)
        cin >> b[i];

    sort(a, a + n);
    sort(b, b + m);

    int l1 = 0, r1 = n - 1, l2 = 0, r2 = m - 1;
    int ans = 0;

    while (l1 <= r1)
    {
        if (abs(a[l1] - b[r2]) > abs(b[l2] - a[r1]))
        {
            ans += abs(a[l1] - b[r2]);
            l1++;
            r2--;
        }
        else if (abs(a[l1] - b[r2]) < abs(b[l2] - a[r1]))
        {
            ans += abs(a[r1] - b[l2]);
            l2++;
            r1--;
        }
        else if (abs(a[l1] - b[r2]) == abs(b[l2] - a[r1]))
        {
            if (l1 != r1)
                ans += 2 * abs(a[l1] - b[r2]);
            else
                ans += abs(a[l1] - b[r2]);

            l1++;
            l2++;
            r1--;
            r2--;
        }
    }

    cout << ans << endl;
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
