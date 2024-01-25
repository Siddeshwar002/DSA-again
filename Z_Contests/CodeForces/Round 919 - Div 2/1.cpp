#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    long long l = INT_MIN, r = INT_MAX;
    set<long long> st;

    while (n--)
    {
        int a, x;
        cin >> a >> x;

        if (a == 1)
        {
            if (l < x)
            {
                l = x;
            }
        }
        else if (a == 2)
        {
            if (x < r)
                r = x;
        }
        else
            st.insert(x);
    }

    long long cnt = 0;
    for (auto it : st)
    {
        if (l <= it && it <= r)
            cnt++;
    }

    int ans = r - l - cnt + 1;
    if (r < l)
        cout << "0" << endl;
    else
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
