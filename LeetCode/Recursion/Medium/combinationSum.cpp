class Solution {
public:
    void helper(vector<int> & candidates, int target, vector<vector<int>> & ans, vector<int> temp, int i){
        if(i >= candidates.size() || target <= 0){
            if(target == 0){
                ans.push_back(temp);
            }
            return;
        }

        temp.push_back(candidates[i]);
        helper(candidates, target - temp.back(), ans, temp, i); // pick candidate - when we pick then we subtract the candidate picked from target so now we just have to search for (target - candidate[i]) as out new target
        temp.pop_back();
        helper(candidates, target, ans, temp, i + 1); // don't pick the candidate


        return;

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>temp;
        helper(candidates, target, ans, temp, 0);


        return ans;
        
    }
};