#include <bits/stdc++.h>
using namespace std;

// ! Recursive code :

class Solution
{
public:
    long long minRefuel(vector<vector<int>> &stations, int idx, int target, int curPos, int curFuel)
    {
        if (idx == stations.size())
        {
            if (target - curPos > curFuel)
                return INT_MAX;
            else
                return 0;
        }

        long long ans = INT_MAX;
        for (int i = idx; i <= stations.size(); i++)
        {
            if (i == stations.size())
            {
                if (target - curPos > curFuel)
                    return INT_MAX;
                else
                    return 0;
            }

            int dis = stations[i][0] - curPos;

            if (curFuel < dis)
                break;

            int tempPos = curPos;
            int tempFuel = curFuel;

            curFuel = curFuel - dis + stations[i][1];
            curPos = stations[i][0];

            ans = min(ans, minRefuel(stations, i + 1, target, curPos, curFuel) + 1);

            curFuel = tempFuel;
            curPos = tempPos;
        }
        return ans;
    }

    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {
        if (startFuel >= target)
            return 0;
        long long ans = minRefuel(stations, 0, target, 0, startFuel);
        return ans == INT_MAX ? -1 : ans;
    }
};

// ! *************************************************************************
// ! Recursive code 2
// * 84/198 Passed

class Solution
{
public:
    long long minRefuel(vector<vector<int>> &stations, int target, int idx, long long curPos, long long curFuel, int stops)
    {
        if (idx == stations.size())
        {
            if (target - curPos > curFuel)
                return INT_MAX;
            else
                return stops;
        }

        long long consider = INT_MAX, notConsider = INT_MAX;
        if (curFuel >= stations[idx][0] - curPos)
        {
            long long dis = stations[idx][0] - curPos;
            consider = minRefuel(stations, target, idx + 1, stations[idx][0], curFuel - (dis) + stations[idx][1], stops + 1);
        }
        notConsider = minRefuel(stations, target, idx + 1, curPos, curFuel, stops);

        return min(consider, notConsider);
    }

    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {
        long long ans = minRefuel(stations, target, 0, 0, startFuel, 0);
        return ans == INT_MAX ? -1 : ans;
    }
};

// ! *********************************************************************************
// ! Tabulaiton
// ! Different approach :

class Solution
{
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {
        int n = stations.size();

        vector<vector<long long>> t(n + 1, vector<long long>(n + 1, 0));
        // t[i][j] = Maximum distance reached if I stopped at 'j' fuelStops from total of 'i' fuelStops
        // i.e. j <= i

        // If j = 0, i.e. I did not use any fuelStops, Then maximum I can reach is 'startFuel' which I had initially
        // So, initialize the dp array with this information
        for (int i = 0; i < n + 1; i++)
        {
            t[i][0] = startFuel;
        }

        // There is no point of filling 1st row because
        // t[0][j] means I used j fuelStops from 0 fuelStops which doesn't make any sense for (j>0)
        // That's why I start from i = 1 and obviously j = 1 because for j = 0 we already populated the dp array

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                // I can use j=1 to j=i fuel stops and find max distance for t[i][j]
                // case-1 (I don't refuel at current fuelstop)
                // If I didn't refuel at current stop, the max distance I can cover is equal to maximum
                // distance I could cover from previous state
                t[i][j] = t[i - 1][j];

                // case-2 (I will refuel at current fuelStop)
                // But check if you can even reach this station (stations[i-1][0]) or not from your previous station
                if (t[i - 1][j - 1] >= stations[i - 1][0])
                {
                    t[i][j] = max(t[i][j], t[i - 1][j - 1] + stations[i - 1][1]);
                }
            }
        }

        // After you end up with all stations, check which t[n][j] was best for reaching target
        // Best means, minimum j used by you to reach target
        for (int j = 0; j < n + 1; j++)
        {
            if (t[n][j] >= target)
                return j;
        }

        // You could never reach target, so return -1
        return -1;
    }
};

// ! *********************************************************************************
// ! Greedy + Max Heap
class Solution
{
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {
        int n = stations.size();

        priority_queue<int> pq; // max heap
        /*
            if we can't reach target, I will first use the largestfuel Station
            (which can take me farthest) and move ahead and keep doing this.
        */
        int curr = startFuel; // my current position
        int i = 0;            // station index
        int result = 0;
        while (curr < target)
        { // until I reach my target
            while (i < n && curr >= stations[i][0])
            {

                pq.push(stations[i][1]);
                // Keep the station at top which can take me farthest (maximum gas)
                i++;
            }

            if (pq.empty()) // we can't move further now
                return -1;

            int dist = pq.top();
            pq.pop();

            curr += dist;
            result++;
        }

        return result;
    }
};
