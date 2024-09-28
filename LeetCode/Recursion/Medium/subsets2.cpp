

/*
Note the best approach as time complexity is more - My Solution
*/

class Solution {
public:
    void helper(vector<int> arr, int i, int n, set<vector<int>> &ans,
                vector<int> temp) {
        if (i >= n) {
            ans.insert(temp);
            return;
        }

        temp.push_back(arr[i]);
        helper(arr, i + 1, n, ans, temp);
        temp.pop_back();
        helper(arr, i + 1, n, ans, temp);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> tempAns;
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        
        helper(nums, 0, nums.size(), tempAns, {});

        for (auto i : tempAns) {
            ans.push_back(i);
        }

        return ans;
    }
};




// Best Approach

class Solution {
public:
    void helper(vector<int> arr, int index, int n, vector<vector<int>> &ans,
                vector<int> temp) {
        ans.push_back(temp);

        for(int i = index; i < n; i++){
            if(i > index && arr[i] == arr[i - 1]) continue;
            temp.push_back(arr[i]);
            helper(arr, i + 1, n, ans, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        
        helper(nums, 0, nums.size(), ans, {});
        return ans;
    }
};