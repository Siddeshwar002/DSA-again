#include <iostream>
#include <vector>

using namespace std;

/*
- Modification of Count inversions - [arr[i] > arr[j]] : [i < j]

QUESTION :
A subsequence is created by deleting zero or more elements from a list while maintaining the order.
For example, the subsequences of [1,2,3] are [1], [2], [3], [1,2], [1,3], [2,3], [1,2,3].
An inversion is a strictly decreasing subsequence of length 3.
More formally, given an array, p = p[n] an inversion in the array is any time some p[i] > p[j]>p[k] and i<j<k.
*/

int mergeBoth(vector<int> &arr, int low, int mid, int high, int ele)
{
    int left = low;
    int right = mid + 1;
    int cnt = 0;
    vector<int> tmp;

    while (left <= mid && right <= high)
    {
        // Changes need to be done here
        if (arr[left] > arr[right] && ele > arr[left])
        {
            cnt += (mid - left + 1);
            tmp.push_back(arr[right]);
            right++;
        }
        else if (arr[left] <= arr[right])
        {
            tmp.push_back(arr[left]);
            left++;
        }
    }

    while (left <= mid)
    {
        tmp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        tmp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = tmp[i - low];
    }
    return cnt;
}

int merge(vector<int> &arr, int low, int high, int ele)
{
    int cnt = 0;
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        cnt += merge(arr, low, mid, ele);
        cnt += merge(arr, mid + 1, high, ele);
        cnt += mergeBoth(arr, low, mid, high, ele);
    }
    return cnt;
}

int solve(vector<int> arr)
{
    int n = arr.size();

    if (n < 3)
        return 0;

    int high = n - 1;
    int ans = 0;

    for (int low = 1; low <= n - 1; low++)
    {
        ans += merge(arr, low, high, arr[low - 1]);
    }
    return ans;
}

int main()
{
    vector<int> arr = {5, 3, 4, 2, 1};
    vector<int> arr2 = {4, 2, 2, 1};
    vector<int> arr3 = {4, 1, 3, 2, 5};

    cout << solve(arr) << endl;
    cout << solve(arr2) << endl;
    cout << solve(arr3) << endl;

    return 0;
}