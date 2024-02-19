#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; ++i)

void solve()
{
    int n;
    cin>>n;

    string s;
    cin>>s;

    int firstB = -1; 
    int lastB = -1; 


    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == 'B')
        {
            if (firstB == -1)
            {
                firstB = i; 
            }
            lastB = i; 
        }
    }

    cout<<lastB-firstB+1<<endl;
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
