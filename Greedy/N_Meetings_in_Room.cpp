#include <bits/stdc++.h>
using namespace std;

int maxMeetings(int start[], int end[], int n)
{
    pair<int,int> a[n+1];
    for (int i=0;i<n;i++){
        a[i].first = end[i];
        a[i].second = i;
    }

    sort(a, a+n);

    int time_limit = a[0].first;

    vector<int> m;

    m.push_back(a[0].second + 1);

    for(int i=1; i<n; i++){
        if (start[a[i].second] > time_limit)
        {
            m.push_back(a[i].second + 1);
            time_limit = a[i].first;
        }
    }
    return m.size();
}

int main()
{
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[] = {2, 4, 6, 7, 9, 9};
    int N = 6;

    int ans = maxMeetings(start, end, N);
    return 0;
}

// 48 43 61 54 99 84 3 3 59 30 45 72 24 87 21 48 54 88 8 67 41 64 87 54 5 62 87 33 74 92
// 150 67 137 131 139 115 49 6 117 126 59 109 27 96 73 60 99 108 50 145 68 104 102 82 7 126 118 93 148 150