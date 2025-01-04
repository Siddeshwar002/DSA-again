#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/design-a-stack-with-increment-operation/

class CustomStack
{
private:
    vector<int> stack;
    int maxSize;

public:
    CustomStack(int maxSize)
    {
        this->maxSize = maxSize;
    }

    void push(int x)
    {
        if (stack.size() < maxSize)
        {
            stack.push_back(x);
        }
    }

    int pop()
    {

        if (!stack.empty())
        {
            int topElement = stack.back();
            stack.pop_back();
            return topElement;
        }
        return -1;
    }

    void increment(int k, int val)
    {
        for (int i = 0; i < min(k, (int)stack.size()); ++i)
        {
            stack[i] += val;
        }
    }
};
