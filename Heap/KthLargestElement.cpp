#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int left, int right)
{
    int pivot = arr[left];
    int l = left + 1;
    int r = right;

    while (l <= r)
    {
        int Left_ele = arr[l];
        int Right_ele = arr[r];
        
        if (arr[l] < pivot && arr[r] > pivot)
        {
            swap(arr[l], arr[r]);
            l++;
            r--;
        }
        if (arr[l] >= pivot)
        {
            l++;
        }
        if (arr[r] <= pivot)
        {
            r--;
        }
    }
    swap(arr[left], arr[r]);
    return r;
}

int kth_Largest_Element(vector<int> &arr, int k)
{
    int left = 0, right = arr.size() - 1, kth;
    while (1)
    {
        int idx = partition(arr, left, right);
        if (idx == k - 1)
        {
            kth = arr[idx];
            break;
        }
        if (idx < k - 1)
        {
            left = idx + 1;
        }
        else
        {
            right = idx - 1;
        }
    }
    return kth;
}

int main()
{

    vector<int> arr = { 3, 2, 1, 5, 6, 4 , 1};

    int n = arr.size(), k = 1;
    cout << "Kth Largest element is " << kth_Largest_Element(arr, k);
    return 0;
}