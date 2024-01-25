#include <bits/stdc++.h>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; ++i)

void solve()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n, greater<int>());
    int ans = 0;

    for (int i = 0; i <= n - 2; i++)
    {
        for (int j = i + 1; j <= n - 1; j++)
        {
            int low = 0;
            int high = n - 1;

            while (i != low && j != n - 1 && low <= high)
            {
                int mid = (low + high) >> 1;
                if (mid == i || mid == j)
                    break;
                if (arr[mid] < arr[i] + arr[j])
                    high = mid - 1;
                else
                {
                    low = mid + 1;
                }
            }
            ans += (low - (j + 1) + 1);
        }
    }
    cout << ans << endl;
    return;
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
