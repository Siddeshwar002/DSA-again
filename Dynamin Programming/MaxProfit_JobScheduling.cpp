#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<pair<int, int>> &vp, vector<int> &endTime, vector<int> &profit, int idx, int curTime)
{
    if (idx == endTime.size())
        return 0;

    int startTime = vp[idx].first;
    int index = vp[idx].second;

    int consider = 0, notConsider = 0;

    if (curTime <= startTime)
        consider = maxProfit(vp, endTime, profit, idx + 1, endTime[index]) + profit[index];

    notConsider = maxProfit(vp, endTime, profit, idx + 1, curTime);

    return max(consider, notConsider);
}

int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
{
    vector<pair<int, int>> vp;

    for (int i = 0; i < startTime.size(); i++)
    {
        vp.push_back({startTime[i], i});
    }
    sort(vp.begin(), vp.end());

    for(auto it : vp){
        cout<<it.first<<" - "<<endTime[it.second]<<" - "<<profit[it.second]<<endl;
    }

    return maxProfit(vp, endTime, profit, 0, INT_MIN);
}



int main()
{
    vector<int> startTime = {4, 2, 4, 8, 2};
    vector<int> endTime = {5, 5, 5, 10, 8};
    vector<int> profit = {1, 2, 8, 10, 4};

    cout<<jobScheduling(startTime , endTime , profit);
}