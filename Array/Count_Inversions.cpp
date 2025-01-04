// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

// ALL PASSED : long long

long long int merge(vector<long long> &vec, long long int low, long long int mid, long long int high)
{
    long long int count = 0;
    long long int left = low;
    long long int right = mid + 1;
    vector<long long> temp;

    while (left <= mid && right <= high)
    {
        if (vec[left] <= vec[right])
        {
            temp.push_back(vec[left]);
            left++;
        }
        else
        {
            count += (mid - left + 1);
            temp.push_back(vec[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(vec[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(vec[right]);
        right++;
    }

    for (long long int i = low; i <= high; i++)
    {
        vec[i] = temp[i - low];
    }

    return count;
}

long long int mergeSort(vector<long long> &vec, long long int low, long long int high)
{
    long long int count = 0;

    if (low < high)
    {
        long long int mid = low + (high - low) / 2;
        count += mergeSort(vec, low, mid);
        count += mergeSort(vec, mid + 1, high);
        count += merge(vec, low, mid, high);
    }

    return count;
}

long long int inversionCount(long long arr[], long long N)
{
    vector<long long> vec;

    for (long long int i = 0; i < N; i++)
    {
        vec.push_back(arr[i]);
    }

    return mergeSort(vec, 0, N - 1);
}

int main()
{
    long long arr[] = {5, 3, 4, 2, 1};
    long long N = 5;

    long long ans = inversionCount(arr, N);
    cout << "ans " << ans << endl;
}