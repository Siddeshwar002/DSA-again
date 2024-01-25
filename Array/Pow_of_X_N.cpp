#include <bits/stdc++.h>
using namespace std;

// * Best CODE
// ! All test cases passed
// ! TC : log(N)

double myPow(double x, int n)
{
    long long nn = n;

    if (nn < 0)
        nn = (-1) * nn;

    double ans = 1;

    while (nn)
    {
        if (nn % 2 == 0)
        {
            x = x * x;
            nn = nn / 2;
        }
        else
        {
            ans *= x;
            nn--;
        }
    }

    if (n < 0)
        return 1 / ans;
    return ans;
}

// ! TLE : 296/306
double calPow(double x, int n)
{
    if (n == 0)
    {
        return 1.0;
    }
    if (n == 1)
    {
        return x;
    }

    else if (n % 2 == 0)
        return calPow(x, n / 2) * calPow(x, n / 2);
    else
        return calPow(x, n / 2) * calPow(x, n / 2) * x;
}

double myPow(double x, int n)
{
    if (n >= 0)
        return calPow(x, n);
    else
        return 1 / calPow(x, -n);
}

// ! ******************************************************************
// ! TLE : 300/306

// * x = 1.00000
// * n = -2147483648

double myPow(double x, int n)
{
    double ans = 1;

    if (n == 0)
        return 1;

    int N = n;

    if (n < 0)
        N = n * (-1);

    while (N--)
    {
        ans *= x;
    }

    if (n > 0)
        return ans;
    else
        return 1 / ans;
}