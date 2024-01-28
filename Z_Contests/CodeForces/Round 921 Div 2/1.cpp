#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; ++i)

void solve()
{
    int n, k;
    cin >> n >> k;

    int len = n * k;
    string s = "";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            char ch = 'a' + j;
            s += ch;
        }
    }
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
