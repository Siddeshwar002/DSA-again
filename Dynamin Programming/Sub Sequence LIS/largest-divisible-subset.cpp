#include <vector>
#include <iostream>
using namespace std;

/** Rescursive solution :
 *
 * Time limit exceeded : 47/49
 *
 * */
class Solution
{
public:
    void solve(vector<int> &nums, vector<int> &res, vector<int> &ans, int idx)
    {
        if (idx == nums.size())
        {
            if (ans.size() > res.size())
            {
                res = ans;
            }
            return;
        }

        solve(nums, res, ans, idx + 1);

        if (ans.size() == 0 || nums[idx] % ans[ans.size() - 1] == 0)
        {
            ans.push_back(nums[idx]);
            solve(nums, res, ans, idx + 1);
            ans.pop_back();
        }
        return;
    }
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> res, ans;
        solve(nums, res, ans, 0);
        return res;
    }
};

/**Memoization :
 *
 *
 */

/**Tabulation :
 *
 *  - Same code as Longest increasing subsequence
 *
 */
vector<int> divisibleSet(vector<int> &arr)
{
    int n = arr.size();

    // important step
    sort(arr.begin(), arr.end());

    vector<int> dp(n, 1);

    // this stores the previous index
    // needed if we want to print the subsets
    vector<int> hash(n);

    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int prev_index = 0; prev_index < i; prev_index++)
        {
            // condition to check for the subset divisibility
            // arr[i] % arr[prev_index] == 0
            if (arr[i] % arr[prev_index] == 0 && 1 + dp[prev_index] > dp[i])
            {
                dp[i] = 1 + dp[prev_index];
                hash[i] = prev_index;
            }
        }
    }

    // to find the max value for the subset
    int ans = -1;
    int lastIndex = -1;

    for (int i = 0; i < n; i++)
    {
        // find the max in the dp[i]
        // this is the largest subset
        if (dp[i] > ans)
        {
            ans = dp[i];
            lastIndex = i;
        }
    }

    vector<int> temp;

    // start reconstructing the answer from the last element
    temp.push_back(arr[lastIndex]);

    while (hash[lastIndex] != lastIndex)
    {
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }

    reverse(temp.begin(), temp.end());

    return temp;
}

int main()
{
    vector<int> arr = {1, 16, 7, 8, 4};

    vector<int> ans = divisibleSet(arr);

    cout << "The longest divisible subset elements are: ";

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
