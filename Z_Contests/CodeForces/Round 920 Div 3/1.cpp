#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long x, y;
    long long cx, cy;
    long long ans = 0;
    for (long long i = 0; i < 4; i++)
    {
        cin >> cx >> cy;
        if (i == 0)
        {
            x = cx;
            y = cy;
        }
        else
        {
            if (x == cx)
                ans = abs(cy - y);
        }
    }
    cout << ans * ans << endl;
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
    // cout<<"done"<<endl;
}
