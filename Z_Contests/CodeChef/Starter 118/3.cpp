#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; ++i)

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        a.push_back(t);
    }
    sort(a.begin(), a.end());

    int idx = n-1;

    

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
