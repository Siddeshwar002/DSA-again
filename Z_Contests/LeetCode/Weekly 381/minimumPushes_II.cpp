#include <bits/stdc++.h>
using namespace std;

int minimumPushes(string word)
{
    map<char, int> mp;

    for (auto it : word)
    {
        mp[it]++;
    }

    int push = 1;
    int len = 0;
    int ans = 0;

    vector<int> vec;
    for (auto it : mp)
    {
        vec.push_back(it.second);
    }
    sort(vec.begin(), vec.end(), greater<int>());

    for (auto x : vec)
    {
        ans += (push)*x;
        len++;

        if (len == 8)
        {
            len = 0;
            push++;
        }
    }
    return ans;
}