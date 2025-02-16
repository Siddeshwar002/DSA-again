#include <vector>
using namespace std;

// Approach 1 : 
// Single Peak Element 
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        
        if(nums.size() == 1)return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-2] < nums[n-1]) return n-1;

        int lo = 1, hi = nums.size()-2;

        while(lo <= hi){
            
            int mid = lo+(hi-lo)/2;
            
            if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1])
                return mid;
            
            else if(nums[mid] < nums[mid+1])
                lo = mid + 1;
            
            else if(nums[mid] > nums[mid+1])
                hi = mid - 1;
        }

        return -1;
    }

};

// Modification : 
// What to do if there are multiple Peak element ? 
//      - here we reach a valley point

// What to do if there are duplicate elements ? 
//      - here we reach a plateau point 

// you need to add an extra case to handle the Plateau
// If none of the existing cases are true then move either to the right or to the left 

int main(){
    Solution s;
    vector<int> arr = {1,2,3,1};
    s.findPeakElement(arr);

}