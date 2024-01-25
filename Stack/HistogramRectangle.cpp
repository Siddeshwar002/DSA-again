#include <bits/stdc++.h>
using namespace std;

// ! ********************************************************************
// * Approach 1 : Optimized

int largestRectangleArea(vector<int> &arr)
{
    stack<int> st;
    int area = 0;
    int n = arr.size();

    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() && (i == n || arr[st.top()] >= arr[i]))
        {
            int cur = st.top();
            st.pop();
            int l = 0, r = i;

            if (!st.empty())
                l = st.top() + 1;

            area = max(area, arr[cur] * (r - l));
        }
        st.push(i);
    }
    return area;
}

// ! ********************************************************************
// * Approach 2 : leftSmall, rightSmall array

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    stack<int> st;
    int leftsmall[n], rightsmall[n];
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }
        if (st.empty())
            leftsmall[i] = 0;
        else
            leftsmall[i] = st.top() + 1;
        st.push(i);
    }
    // clear the stack to be re-used
    while (!st.empty())
        st.pop();

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
            st.pop();

        if (st.empty())
            rightsmall[i] = n - 1;
        else
            rightsmall[i] = st.top() - 1;

        st.push(i);
    }
    int maxA = 0;
    for (int i = 0; i < n; i++)
    {
        maxA = max(maxA, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
    }
    return maxA;
}