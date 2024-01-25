#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int> &nums)
{
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;

    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
            mid++;
        else if (nums[mid] == 2)
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

// * Low Pointer (low): It keeps track of the boundary for 0s (red).
// It ensures that all elements before this pointer are red (0).

// * Mid Pointer (mid): This pointer traverses the array.
// It is used to inspect elements in the array and move them to their correct positions.

// * High Pointer (high): It keeps track of the boundary for 2s (blue).
// It ensures that all elements after this pointer are blue (2).