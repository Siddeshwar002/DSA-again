// https: // leetcode.com/problems/single-element-in-a-sorted-array/

#include "../stdc++.h"
using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();

        // edge cases
        if (n == 0)
            return -1;
        if (n == 1)
            return nums[0];

        // edge case - ONLY two elements
        if (nums[0] != nums[1])
            return nums[0];

        if (nums[n - 2] != nums[n - 1])
            return nums[n - 1];

        int low = 1;
        int high = n - 2;

        while (low <= high)
        {
            int mid = (low + high) >> 1;

            // Found that single element
            if (nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1])
                return nums[mid];

            else if (mid % 2 == 0 && nums[mid] == nums[mid + 1] || mid % 2 == 1 && nums[mid - 1] == nums[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};