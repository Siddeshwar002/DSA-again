// https : // leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

#include <bits/stdc++.h>
using namespace std;

// Stack Approach
// TC : O(N)
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;

        stack<int> st;
        for (auto ele : prices)
        {
            if (st.empty())
                st.push(ele);
            else if (st.size() == 1 && st.top() > ele)
            {
                st.pop();
                st.push(ele);
            }
            else if (st.size() == 2 && st.top() > ele)
            {
                int F = st.top();
                st.pop();
                int S = st.top();
                st.pop();
                profit += (F - S);
                st.push(ele);
            }
            else if (st.size() == 1 && st.top() < ele)
            {
                st.push(ele);
            }
            else if (st.size() == 2 && st.top() < ele)
            {
                st.pop();
                st.push(ele);
            }
        }

        if (st.size() == 2)
        {
            int F = st.top();
            st.pop();
            int S = st.top();
            st.pop();

            profit += (F - S);
        }
        return profit;
    }
};

// *****************************************************************************************************
// One-pass solutino
// without using stack

#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;

        for (int i = 1; i < prices.size(); ++i)
        {
            // If the current price is greater than the previous one, add the difference to profit
            if (prices[i] > prices[i - 1])
            {
                profit += prices[i] - prices[i - 1];
            }
        }

        return profit;
    }
};

// *****************************************************************************************************
