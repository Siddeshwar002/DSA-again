#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; ++i)

bool isPrime(int num)
{
    if (num < 2)
    {
        return false;
    }
    for (int i = 2; i * i <= num; ++i)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> p(n);
    loop(i, n)
    {
        cin >> p[i];
    }

    vector<int> a(n);
    iota(a.begin(), a.end(), 1);

    // Check if the current permutation satisfies the condition
    auto satisfiesCondition = [&]()
    {
        loop(i, n)
        {
            if (isPrime(a[i] + p[i]))
            {
                return false;
            }
        }
        return true;
    };

    // Try different permutations until a valid one is found
    while (!satisfiesCondition())
    {
        next_permutation(a.begin(), a.end());
    }

    // Print the valid permutation
    loop(i, n)
    {
        cout << a[i] << " ";
    }
    cout << endl;
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

    return 0;
}
