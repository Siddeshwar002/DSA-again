#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; ++i)
const int MOD = 998244353;
void solve()
{
    int row, col;
    cin >> row >> col;

    if (row > col)
        swap(row, col);

    if (row == col)
    {
        if (row % 2 == 1)
        {
            int ans = (int)row / 2 + 1;
            cout << (ans * ans) % MOD;
            return;
        }
        else
        {
            int r1 = row / 2;
            int r2 = r1 + 1;

            int c1 = r1;
            int c2 = r2;

            int ans = 0;

            for (int i = r1; i <= r2; i++)
            {
                for (int j = c1; j <= c2; j++)
                {
                    ans += i * j;
                }
            }

            cout << ans % MOD << endl;
            return;
        }
    }
    else
    {
        int c1 = -1, c2 = -1;

        int maxLimt = col / 2;
        if (col % 2 == 0)
        {
            c1 = col / 2;
            c2 = c1 + 1;
        }
        else
        {
            c1 = col / 2 + 1;
            c2 = -1;
        }

        int ul = 1, ll = row;

        if (maxLimt < row - 1)
        {
            ul += (row - 1) - maxLimt;
            ll -= (row - 1) - maxLimt;
        }

        int ans = 0;
        if (c2 == -1)
        {
            for (int i = ul; i <= ll; i++)
            {
                ans += i * c1;
            }
            cout << ans % MOD << endl;
        }
        else
        {

            for (int i = ul; i <= ll; i++)
            {
                ans += i * c1;
            }

            for (int i = ul; i <= ll; i++)
            {
                ans += i * c2;
            }
            cout << ans % MOD << endl;
        }
    }
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
