#include <iostream>
#include <set>
#include <vector>
using namespace std;

// Apprach 1 :
// MaxProduct and MinProduct

class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int n = nums.size();
    if (n == 0)
      return 0;

    int maxProd = nums[0];
    int minProd = nums[0];
    int ans = nums[0];

    for (int i = 1; i < n; i++) {
      if (nums[i] < 0)
        swap(maxProd, minProd);

      maxProd = max(nums[i], maxProd * nums[i]);
      minProd = min(nums[i], minProd * nums[i]);

      ans = max(ans, maxProd);
    }

    return ans;
  }
};

/** Approach 2 :
 *       - Prefix product
 *       - Suffix Product
 */
int maxProductSubArray(vector<int> &arr) {
  int n = arr.size();

  int pre = 1, suff = 1;
  int ans = INT_MIN;
  for (int i = 0; i < n; i++) {
    if (pre == 0)
      pre = 1;
    if (suff == 0)
      suff = 1;
    pre *= arr[i];
    suff *= arr[n - i - 1];
    ans = max(ans, max(pre, suff));
  }
  return ans;
}
