#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        map<int,int> mp;
        for(auto x : nums)
            mp[x]++;
        
        int ans = 0;
        for(auto x : mp){
            if(x.second == 1)
                ans++;
            else{
                for(int i = -k ; i<= k ; i++){
                    
                    if(mp.find(x.first + (i)) == mp.end()){
                        mp[x.first + (i)] = 1;
                        ans++;
                        mp[x.first]--;
                    }
                    
                    if(mp[x.first] == 1){
                        ans++;
                        break;
                    }
                }
            }
        }
        cout<<"mp"<<mp.size()<<endl;
        for(auto x : mp)
            cout<<'x'<<x.first<<" "<<x.second<<endl;
        
        if(mp.size() >= nums.size())
            return nums.size();
        else 
            return mp.size();
        
 
    }
};
int main()
{
    Solution S;
    // vector<int> nums = {1, 2, 2, 3, 3, 4};
    vector<int> nums = {8, 8, 10, 9, 9};
    int k = 1;

    cout << S.maxDistinctElements(nums, k) << endl;
}