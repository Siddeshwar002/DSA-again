#include <bits/stdc++.h>
using namespace std;

priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;

void addNum(int num)
{
    if (maxHeap.empty() || num <= maxHeap.top())
    {
        maxHeap.push(num);
    }
    else
    {
        minHeap.push(num);
    }

    if (maxHeap.size() > minHeap.size() + 1)
    {
        minHeap.push(maxHeap.top());
        maxHeap.pop();
    }
    else if (minHeap.size() > maxHeap.size())
    {
        maxHeap.push(minHeap.top());
        minHeap.pop();
    }
}

double findMedian()
{
    if (maxHeap.empty())
    {
        return 0; // or handle the case where there's no median value
    }

    if (minHeap.size() == maxHeap.size())
    {
        return (double)(minHeap.top() + maxHeap.top()) / 2;
    }
    else
    {
        return maxHeap.top();
    }
}