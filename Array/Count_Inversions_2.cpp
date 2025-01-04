// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int> &nums, int low, int mid, int high)
{
    int count = 0;
    int left = low;
    int right = mid + 1;

    // ! modified count loop (left > 2*right)
    while (left <= mid && right <= high)
    {
        if ((long long)nums[left] > 2LL * nums[right])
        {
            // ! Using long long to handle larger values
            // ! integer out of range possiblity

            count += (mid - left + 1);
            right++;
        }
        else
        {
            left++;
        }
    }

    // Merge two sorted halves
    vector<int> temp;
    left = low;
    right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (nums[left] <= nums[right])
        {
            temp.push_back(nums[left]);
            left++;
        }
        else
        {
            temp.push_back(nums[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(nums[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(nums[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        nums[i] = temp[i - low];
    }

    return count;
}

int mergeSort(vector<int> &nums, int low, int high)
{
    if (low >= high)
    {
        return 0;
    }

    int mid = low + (high - low) / 2;
    int count = 0;
    count += mergeSort(nums, low, mid);
    count += mergeSort(nums, mid + 1, high);
    count += merge(nums, low, mid, high);

    return count;
}

int reversePairs(vector<int> &nums)
{
    return mergeSort(nums, 0, nums.size() - 1);
}

int main()
{
    vector<int> a = {5, 4, 3, 2, 1};
    int n = 5;
    int cnt = reversePairs(a);
    cout << "The number of inversions are: "
         << cnt << endl;
    return 0;
}
