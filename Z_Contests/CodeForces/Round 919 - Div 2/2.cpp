#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, a, x;
    cin >> n >> a >> x;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort((arr), arr + n);

    int a2 = n - x - 1;
    int Sum1 = 0, Sum2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (i <= a2)
            Sum1 += arr[i];
        else
            Sum2 += arr[i];
    }

    int ans = Sum1 - Sum2;
    int l = a2;
    int r = n - 1;

    if (a == 0)
        cout << ans << endl;
    else
    {
        while (a-- && r >= 0)
        {
            if (l >= 0)
            {
                Sum1 -= arr[l];
                Sum2 += arr[l];
                l--;
            }

            Sum2 -= arr[r];
            r--;

            ans = max(ans, Sum1 - Sum2);
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
