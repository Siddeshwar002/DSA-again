#include <bits/stdc++.h>
using namespace std;

// Memoization Code
// O(N^2)
// Can handle up to 10^3
// but n <= 10^9

class Solution
{
public:
    double probSoup(int A, int B, int l, std::unordered_map<std::string, double> &memo)
    {
        if (A <= 0 && B <= 0 && A == B)
            return (0.5) * (1 / pow(4, l));

        if (A <= 0 && B > A)
            return (1 / pow(4, l));

        if (B <= 0 && A > B)
            return 0;

        std::string key = std::to_string(A) + "|" + std::to_string(l);

        if (memo.find(key) != memo.end())
            return memo[key];

        int a[] = {100, 75, 50, 25};
        int b[] = {0, 25, 50, 75};

        double prob = 0;
        for (int i = 0; i < 4; i++)
        {
            prob += probSoup(A - a[i], B - b[i], l + 1, memo);
        }

        memo[key] = prob;
        return prob;
    }

    double soupServings(int n)
    {
        std::unordered_map<std::string, double> memo;

        return probSoup(n, n, 0, memo);
    }
};

// ***************************************************************************
// Memoization
// Binary Search --> to find the limit
// look into the hints

class Solution
{
public:
    double probSoup(int A, int B, int l, unordered_map<string, double> &memo)
    {
        if (A <= 0 && B <= 0 && A == B)
            return (0.5) * (1 / pow(4, l));

        if (A <= 0 && B > A)
            return (1 / pow(4, l));

        if (B <= 0 && A > B)
            return 0;

        string key = to_string(A) + "|" + to_string(l);

        if (memo.find(key) != memo.end())
            return memo[key];

        int a[] = {100, 75, 50, 25};
        int b[] = {0, 25, 50, 75};

        double prob = 0;
        for (int i = 0; i < 4; i++)
        {
            prob += probSoup(A - a[i], B - b[i], l + 1, memo);
        }

        memo[key] = prob;
        return prob;
    }

    int binary_search_limit(int low, int high, double epsilon)
    {
        while (high - low > 1)
        {
            int mid = low + (high - low) / 2;
            double result = this->soupServings(mid);

            if (abs(result - 1.0) <= epsilon)
            {
                high = mid;
            }
            else
            {
                low = mid;
            }
        }
        return high;
    }

    double soupServings(int n)
    {
        // int N = binary_search_limit(1000, 2000 , 1e-5);
        int N = 4800;

        if (n > N)
        {
            return 1.0;
        }
        unordered_map<string, double> memo;

        return probSoup(n, n, 0, memo);
    }
};
