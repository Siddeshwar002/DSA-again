#include <bits/stdc++.h>
using namespace std;

// Montonic stack concept
vector<int> nextGreaterElements(vector<int> &nums)
{
    stack<int> st;
    int n = nums.size();
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {

        while (!st.empty() && st.top() < nums[i])
            st.pop();

        if (!st.empty() && st.top() > nums[i])
        {
            ans[i] = st.top();
        }
        else if (st.empty())
            ans[i] = -1;

        st.push(nums[i]);
    }

    return ans;
}

