#include <bits/stdc++.h>
using namespace std;

// ! Binary Search on Answer to find 'num'
// ! Binary approach in calculating 'BitSum' for that 'num'

void bitSum(long long n, vector<long long> &bSum)
{
    if (n == 0)
        return;

    if (n == 1)
    {
        bSum[0] += 1;
        return;
    }
    if (n == 2)
    {
        bSum[1] += 1;
        bSum[0] += 1;
        return;
    }

    long long ln = log2(n);
    long long cn = (1LL << ln);
    bSum[ln] += n - cn + 1;

    for (long long i = 0; i < ln; i++)
    {
        bSum[i] += cn / 2;
    }

    n -= cn;
    bitSum(n, bSum);
    return;
}

long long findMaximumNumber(long long k, long long x)
{
    long long low = x, high = 1e15;

    while (low <= high)
    {
        long long mid = (low + high) >> 1;

        long long len = log2(mid);
        vector<long long> bSum(len + 1, 0);

        bitSum(mid, bSum);
        long long ans = 0;

        for (long long i = 0; i <= len; i++)
        {
            if ((i + 1) % x == 0)
                ans += bSum[i];
        }

        if (ans <= k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return low - 1;
}