#include <vector>
#include <iostream>
using namespace std;

int solve(int n, vector<int> &dp)
{
    if (n == 0)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n - i < 0)
            break;
        sum += solve(n - i, dp);
    }
    return dp[n] = sum;
}

int all_distinct_ways_to_climb_stairs(int n)
{
    vector<int> dp(n + 1, -1);
    cout << solve(3, dp) << endl;
    return solve(3, dp);
}

int main()
{
    all_distinct_ways_to_climb_stairs(3);
    return 0;
}