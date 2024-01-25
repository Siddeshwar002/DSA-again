#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s)
{
    if (s.length() == 0)
        return 0;

    map<char, int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;

    if (s.length() == 1)
        return mp[s[0]];

    int Cursum = mp[s[0]];
    int TotSum = 0;

    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == s[i - 1])
        {
            Cursum += mp[s[i]];
        }
        else
        {
            if (Cursum > mp[s[i]])
            {
                TotSum += Cursum;
                Cursum = mp[s[i]];
            }
            else
            {
                int Tsum = mp[s[i]] - Cursum;
                Cursum = Tsum;
            }
        }
    }
    return TotSum+Cursum;
}

int main()
{
    cout << "Ans : " << romanToInt("MDCCCLV");
}