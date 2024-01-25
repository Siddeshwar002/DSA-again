#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSquares(int l, int b)
    {
        if (l <= 0 || b <= 0)
            return 0;

        // ! Hard Coded Test cases Lol

        // if(l == 11 && b == 13 || l == 13 && b == 11)
        //     return 6;
        // if(l == 7 && b == 6 || l == 6 && b == 7)
        //     return 5;
        // if(l == 11 && b == 10 || l==10 && b == 11)
        //     return 6;

        int a = min(l, b);

        int ans = INT_MAX;
        for (int i = 1; i <= a; i++)
        {
            ans = min(ans, minSquares(i, l - i) + minSquares(i, b - i) + 1);
        }
        return ans;
    }

    int tilingRectangle(int n, int m)
    {
        return minSquares(n, m);
    }
};