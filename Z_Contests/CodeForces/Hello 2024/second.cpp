#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    int p = 0;
    int m = 0;

    for (auto c : s)
    {
        if (c == '+')
            p++;
        else
            m++;
    }

    cout << abs(p - m) << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}