#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{   
    unordered_set<int> s;

    for (auto it : nums)
    {
        s.insert(it);
    }

    int len = INT_MIN;
    while (!s.empty())
    {
        auto curEle = s.begin();
        int cnt = 1;

        while (s.find(*curEle - 1) != s.end())
        {
            auto it = s.find(*curEle - 1);
            curEle = it;
        }

        while (s.find(*curEle + 1) != s.end())
        {
            auto prev = curEle;
            auto it = s.find(*curEle + 1);
            s.erase(prev);
            curEle = it;
            cnt++;
        }
        s.erase(curEle);
        len = max(len, cnt);
    }

    return len;
}

int main()
{
    vector<int> nums = { 0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << "The length of the longest consecutive elements is: " << longestConsecutive(nums) << endl;
}