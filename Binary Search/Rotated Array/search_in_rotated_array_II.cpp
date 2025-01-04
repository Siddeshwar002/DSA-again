#include "../../stdc++.h"
using namespace std;

class Solution
{
public:
    bool search(vector<int> &arr, int target)
    {
        int n = arr.size();
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;

            // if mid points the target
            if (arr[mid] == target)
                return 1;

            // To hanle duplicates
            // [3,1,2,3,3,3,3]
            // In this case we don't know which part was sorted
            // I will eliminate the lo and hi becasue
            // I anyways have the same element as mid still in my search space
            if (arr[low] == arr[mid] && arr[mid] == arr[high])
            {
                low++;
                high--;
                continue;
            }

            // if left part is sorted:
            if (arr[low] <= arr[mid])
            {
                if (arr[low] <= target && target <= arr[mid])
                {
                    // element exists:
                    high = mid - 1;
                }
                else
                {
                    // element does not exist:
                    low = mid + 1;
                }
            }
            else
            { // if right part is sorted:
                if (arr[mid] <= target && target <= arr[high])
                {
                    // element exists:
                    low = mid + 1;
                }
                else
                {
                    // element does not exist:
                    high = mid - 1;
                }
            }
        }
        return 0;
    }
};