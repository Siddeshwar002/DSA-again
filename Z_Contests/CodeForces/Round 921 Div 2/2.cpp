#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; ++i)

int GCD(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void solve()
{
    int x, n;
    cin >> x >> n;

    if (x % n == 0)
    {
        cout << x / n << endl;
    }
    else
    {
        int d = x / n;
        int ans = 1;

        for (int i = d; i > 1; i--)
        {
            int dx = x - i * (n - 1);
            if (dx % i == 0)
            {
                ans = i;
                break;
            }
            ans = max(ans, GCD(dx, i));
        }
        cout << ans << endl;
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
