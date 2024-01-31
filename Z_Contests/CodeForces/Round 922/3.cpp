#include <iostream>

using namespace std;

void solve()
{
    long long a, b, r;
    cin >> a >> b >> r;

    // XOR of a and b
    long long x = a ^ b;

    // Find the leftmost differing bit in x
    int leftmostBit = 63 - __builtin_clzll(x);

    // Set all bits to the left of the leftmost differing bit to 1
    long long mask = (1LL << (leftmostBit + 1)) - 1;

    // Find the smallest value of |(a⊕x)−(b⊕x)|
    long long result = (a ^ (x & mask)) + (b ^ (x & mask));

    cout << result << endl;
}

int main()
{
    ios::sync_with_stdio(false);
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
