#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; ++i)

void solve()
{
    int n;
    cin >> n;

    int arr[n];
    loop(i, n) { cin >> arr[i]; }

    map<int, deque<char>> charMap;

    deque<char> charVector;
    for (char ch = 'a'; ch <= 'z'; ++ch)
    {
        charVector.push_back(ch);
    }
    charMap[0] = charVector;

    string s;
    for (int i = 0; i < n; i++)
    {
        char c = charMap[arr[i]].front();
        s += c;
        charMap[arr[i]].pop_front();
        charMap[arr[i] + 1].push_back(c);
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
