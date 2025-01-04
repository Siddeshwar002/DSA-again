#include "stdc++.h"
using namespace std;

int findPlatform(int arr[], int dep[], int n)
{
    priority_queue<int, vector<int>, greater<int>> q;
    pair<int, int> times[n];

    for (int i = 0; i < n; i++)
    {
        times[i] = make_pair(arr[i], dep[i]);
    }

    // Sorts according to the first element
    sort(times, times + n);

    if (n == 0)
        return -1;

    int i = 1;

    // You always need atleast on track
    int ans = 1;

    // Allot the first arrival train to the track - 1
    q.push(times[0].second);

    // For all the trains
    while (i < n)
    {
        int minEle = q.top();

        if (times[i].first <= minEle)
        {
            ans++;
        }
        else if (times[i].first > minEle)
        {
            q.pop();
        }
        q.push(times[i].second);
        i++;
    }

    // int ans = q.size();
    return ans;
}