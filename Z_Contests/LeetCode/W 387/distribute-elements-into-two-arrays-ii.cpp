#include <bits/stdc++.h>
using namespace std;

// 1.
// TLE
// 780/784 Passed
// using mulitset and upper_bound function

class Solution
{
public:
    vector<int> resultArray(vector<int> &nums)
    {
        multiset<int> s1, s2;
        vector<int> v1, v2;
        s1.insert(nums[0]);
        v1.push_back(nums[0]);
        s2.insert(nums[1]);
        v2.push_back(nums[1]);

        for (int i = 2; i < nums.size(); i++)
        {
            int idx1 = s1.size() - distance(s1.begin(), s1.upper_bound(nums[i]));
            int idx2 = s2.size() - distance(s2.begin(), s2.upper_bound(nums[i]));

            if (idx1 > idx2)
            {
                s1.insert(nums[i]);
                v1.push_back(nums[i]);
            }
            else if (idx1 < idx2)
            {
                s2.insert(nums[i]);
                v2.push_back(nums[i]);
            }
            else
            {
                if (s1.size() > s2.size())
                {
                    s2.insert(nums[i]);
                    v2.push_back(nums[i]);
                }
                else
                {
                    s1.insert(nums[i]);
                    v1.push_back(nums[i]);
                }
            }
        }

        vector<int> ans;
        ans.insert(ans.end(), v1.begin(), v1.end());
        ans.insert(ans.end(), v2.begin(), v2.end());

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2, 47, 3, 3, 65, 7, 97, 4};
    s.resultArray(nums);
}

// 2.
// striaght forward vector approach
// Inserting new element to its pos -> this makes sure the vectors are always sorted
// We can get the pos to be inserted by using upper_bound function on the vector
// as the vector is already sorted

// Accepted

class Solution
{
public:
    int greaterCount(vector<int> &arr, int val)
    {
        return arr.end() - upper_bound(arr.begin(), arr.end(), val);
    }

    vector<int> resultArray(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> left, right, ll, rr;
        left.push_back(nums[0]);
        right.push_back(nums[1]);
        ll.push_back(nums[0]);
        rr.push_back(nums[1]);

        int l = 0, r = 0;

        for (int i = 2; i < n; i++)
        {
            int x = greaterCount(left, nums[i]);
            int y = greaterCount(right, nums[i]);

            if (x > y)
            {

                left.insert(left.end() - x, nums[i]);
                ll.push_back(nums[i]);
                l++;
            }
            else if (x < y)
            {

                right.insert(right.end() - y, nums[i]);
                rr.push_back(nums[i]);
                r++;
            }
            else
            {
                if (l <= r)
                {

                    left.insert(left.end() - x, nums[i]);
                    ll.push_back(nums[i]);
                    l++;
                }
                else
                {

                    right.insert(right.end() - y, nums[i]);
                    rr.push_back(nums[i]);
                    r++;
                }
            }
        }

        ll.insert(ll.end(), rr.begin(), rr.end());
        return ll;
    }
};
