// https://leetcode.com/problems/combination-sum/

class Solution {
public:
    void Solve(vector<int>& candidates, int target , vector<vector<int>> &ans , vector<int> &vec , int idx){

        if(target == 0){
            ans.push_back(vec);
            return;
        }

        if(idx >= candidates.size()){
            return;
        }

        for(int i = idx; i < candidates.size(); i++){
            if(i > 0 && candidates[i-1] == candidates[i])continue;

            if(target >= candidates[i]){
                vec.push_back(candidates[i]);
                Solve(candidates, target - candidates[i] , ans, vec, i);
                vec.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // Sort the vector
        vector<vector<int>> ans;
        vector<int> vec;

        sort(candidates.begin() , candidates.end());

        Solve(candidates, target, ans, vec, 0);
        return ans;

    }
};