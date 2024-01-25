#include <bits/stdc++.h>
using namespace std;

// ! Approach 1 :

// * Dynammic Programming
// * Memory limit exceeded

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));

    for (int window = 0; window < k; window++)
    {
        for (int start = 0; start < nums.size() - window; start++)
        {
            int end = start + window;

            if (start == end)
            {
                dp[start][window] = nums[end];
            }
            else
            {
                dp[start][window] = max(dp[start][window - 1], nums[end]);
            }
        }
    }
    vector<int> ans;

    // for(int j  = 0 ; j < k ; j++){
    for (int i = 0; i < nums.size() - k + 1; i++)
    {

        cout << dp[i][k - 1] << " ";
        ans.push_back(dp[i][k - 1]);
    }
    cout << endl;
    // }

    return ans;
}

// ! ****************************************************************************************
// ! Approach 2 : Max_Priority Queue
// * ACCEPTED
// * TC : O(N logN)
// * SC : O(K)

vector<int> maxSlidingWindow2(vector<int> &nums, int k)
{
    priority_queue<pair<int, int>> qp;
    vector<int> ans;

    for (int i = 0; i <= nums.size(); i++)
    {
        if (i >= k)
        {
            while (!qp.empty() && qp.top().second < i - k)
                qp.pop();

            ans.push_back(qp.top().first);
        }
        if (i < nums.size())
            qp.push({nums[i], i});
    }
    return ans;
}

// ! ****************************************************************************************
// ! Approach 3 : Dequeue
// * BEST Solution
// * TC : O(N)

vector<int> maxSlidingWindow3(vector<int> &nums, int k)
{
    vector<int> result;
    if (k == 0)
        return result;
    deque<int> w;
    for (int i = 0, n = (int)nums.size(); i < n; i++)
    {
        while (!w.empty() && w.front() <= i - k)
            w.pop_front();
        while (!w.empty() && nums[w.back()] <= nums[i])
            w.pop_back();
        w.push_back(i);
        if (i >= k - 1)
            result.push_back(nums[w.front()]);
    }
    return result;
}

int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> vec = maxSlidingWindow2(nums, k);
}