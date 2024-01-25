#include <bits/stdc++.h>
using namespace std;

// ! Approch 1 :
// * TWO STACKS

// * Refer MiniStack_2.cpp for some smart and better code

class MinStack
{
private:
    stack<int> st;
    stack<pair<int, int>> minSt;

public:
    MinStack() {}

    void push(int val)
    {
        if (minSt.empty() || val <= minSt.top().first)
        {
            minSt.push({val, st.size()});
        }
        st.push(val);
    }

    void pop()
    {
        if (!st.empty())
        {
            if (st.size() - 1 == minSt.top().second)
            {
                minSt.pop();
            }
            st.pop();
        }
    }

    int top()
    {
        if (!st.empty())
        {
            return st.top();
        }
        return -1; // Handle empty stack case
    }

    int getMin()
    {
        if (!minSt.empty())
        {
            return minSt.top().first;
        }
        return -1; // Handle empty stack case
    }
};