#include <vector>
#include <iostream>
using namespace std;

// Beats 100% Solutions 
// Two pointers approach

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = 0, r = nums.size()-1;
        int cnt = 0;
        
        while(r >= 0 && l < nums.size() && l<=r){
            if(nums[r] == val){
                cnt++;
                r--;
            }else if(nums[l] == val){
                swap(nums[l],nums[r]);
                r--;
                l++;
                cnt++;

            }else
                l++;
        }
        cout<<"cnt "<<cnt<<endl;

        return nums.size()-cnt;

    }
};

int main(){
    vector<int> arr = {0,1,2,2,3,0,4,2};
    Solution s;
    s.removeElement(arr, 2);
}