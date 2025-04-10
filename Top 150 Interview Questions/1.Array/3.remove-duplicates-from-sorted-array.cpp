#include <vector>
using namespace std;

// Most Optimal Approach 

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int n = nums.size();
        int idx = 1;

        for (int i = 1; i < n; ++i) {
            if (nums[i] != nums[i - 1]) {
                nums[idx] = nums[i];
                idx++;
            }
        }

        return idx;
    }
};
