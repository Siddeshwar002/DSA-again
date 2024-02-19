#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; ++i)

bool solveHelp(int i, int a, int b, vector<int> vec1, vector<int> vec2, vector<vector<vector<int>>> &memo)
{
    if (a == 0 && b == 0)
        return true;

    if (memo[i][a][b] != -1)
        return memo[i][a][b];

    if (find(vec1.begin(), vec1.end(), i) != vec1.end() && find(vec2.begin(), vec2.end(), i) != vec2.end())
        return memo[i][a][b] = ((a > 0 && solveHelp(i + 1, a - 1, b, vec1, vec2, memo)) || (b > 0 && solveHelp(i + 1, a, b - 1, vec1, vec2, memo)));

    else if (a > 0 && find(vec1.begin(), vec1.end(), i) != vec1.end())
        return memo[i][a][b] = solveHelp(i + 1, a - 1, b, vec1, vec2, memo);

    else if (b > 0 && find(vec2.begin(), vec2.end(), i) != vec2.end())
        return memo[i][a][b] = solveHelp(i + 1, a, b - 1, vec1, vec2, memo);

    return memo[i][a][b] = false;
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> vec1(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> vec1[i];
    }

    vector<int> vec2(m);
    for (int i = 0; i < m; ++i)
    {
        std::cin >> vec2[i];
    }

    int a = k / 2;
    int b = k / 2;

    vector<vector<vector<int>>> memo(k + 1, vector<vector<int>>(k / 2 + 1, vector<int>(k / 2 + 1, -1)));

    bool ans = solveHelp(1, a, b, vec1, vec2, memo);
    if (ans)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
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
