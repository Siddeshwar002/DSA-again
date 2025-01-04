#include <bits/stdc++.h>
using namespace std;

// TC : O(4N)
// SC : O(2N) + (N)
vector<int> nextGreaterElements(vector<int> &nums)
{
    stack<int> st;
    int n = nums.size();
    vector<int> ans(n, -1);
    for (int i = 2 * n - 1; i >= 0; i--)
    {

        while (!st.empty() && st.top() <= nums[i % n])
            st.pop();

        if (i < n && !st.empty() && st.top() > nums[i % n])
        {
            ans[i] = st.top();
        }

        st.push(nums[i % n]);
    }

    return ans;
}