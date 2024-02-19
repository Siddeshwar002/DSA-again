#include <bits/stdc++.h>
using namespace std;

// Works fine for Find Beautiful Indices in the Given Array I

// but
// Doesn't work for Find Beautiful Binary String !!
// 231/232 PASSED

// ? Refer Find_Beautiful_Indices_in_the_Given_Array_II.cpp
// ? for a better CODE

class Solution
{
public:
    bool isElementInRange(int element, int L, int R)
    {
        return (L <= element && element <= R);
    }

    vector<int> beautifulIndices(string s, string a, string b, int k)
    {
        vector<int> ans;

        size_t positionA = s.find(a);
        size_t positionB = s.find(b);

        while (positionA != string::npos)
        {
            int l = positionA - k;
            int r = positionA + k;

            if (l < 0)
                l = 0;
            if (r > s.length() - 1)
                r = s.length() - 1;

            while (positionB != string::npos && positionB <= r)
            {
                if (isElementInRange(positionB, l, r))
                {
                    ans.push_back(positionA);
                    break; // No need to check other positionsB, move to the next positionA
                }
                positionB = s.find(b, positionB + 1);
            }

            positionA = s.find(a, positionA + 1);
        }

        return ans;
    }
};
