class Solution {
public:
    void getAllSubsets(vector<int> arr, set<vector<int>> & ans, int i, int n, vector<int> temp){
        if(i >= n){
            ans.insert(temp);
            return;
        }

        // take the current element
        temp.push_back(arr[i]);
        getAllSubsets(arr, ans, i + 1, n, temp);
        // remove the current element and just move with the previous values in the array temp
        temp.pop_back();
        getAllSubsets(arr, ans, i + 1, n, temp);
    }

    vector<vector<int>> subsets(vector<int>& arr) {
        set<vector<int>>tempAns;

        vector<int> temp;

        vector<vector<int>> ans;

        getAllSubsets(arr, tempAns, 0, arr.size(), temp);

        for(auto i : tempAns){
            ans.push_back(i);
        }

        return ans;    
    }
};