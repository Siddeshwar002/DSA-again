#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

int maxMeetings(int start[], int end[], int n)
{
    pair<int, int> a[n + 1];

    // creating pair <endTime, idx>
    // To access the start time of the particular job
    // Because we are sorting the endTime[] which will alter the indexing if not stored
    for (int i = 0; i < n; i++)
    {
        a[i].first = end[i];
        a[i].second = i;
    }

    sort(a, a + n);

    int time_limit = a[0].first;

    vector<int> m;

    // add the first job : the one which finishes the earliest
    m.push_back(a[0].second + 1);

    for (int i = 1; i < n; i++)
    {
        // strictly greater than
        if (start[a[i].second] > time_limit)
        {
            // pushing job ids
            m.push_back(a[i].second + 1);

            // updating the time_limit
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