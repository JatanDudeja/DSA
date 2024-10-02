class Solution {
public:
    vector<int> globalArr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    void getCombinationSum2(int index, int sum, vector<int>& arr,
                            vector<vector<int>>& ans, vector<int>& temp,
                            int k) {
        if (k <= 0) {
            if (sum == 0) {
                ans.push_back(temp);
            }
            return;
        }

        for (int i = index; i < arr.size(); i++) {
            if (i > index && arr[i - 1] == arr[i]) {
                // cout << "In continue: " << endl;
                // cout << index << " " << i << " " << sum << endl;
                // for (int j = 0; j < temp.size(); j++) {
                //     cout << temp[i] << " ";
                // }
                // cout << endl;
                continue;
            }
            if (sum < arr[i]) {
                // cout << "In break: " << endl;
                // cout << index << " " << i << " " << sum << endl;
                // for (int j = 0; j < temp.size(); j++) {
                //     cout << temp[i] << " ";
                // }
                // cout << endl;
                break;
            }

            temp.push_back(arr[i]);
            // cout << "Before Recur: " << endl;
            // cout << index << " " << i << " " << sum << endl;
            // for (int j = 0; j < temp.size(); j++) {
            //     cout << temp[i] << " ";
            // }
            // cout << endl;
            getCombinationSum2(i + 1, sum - arr[i], arr, ans, temp, k - 1);
            temp.pop_back();
            // cout << "After Recur: " << endl;
            // for (int j = 0; j < temp.size(); j++) {
            //     cout << temp[i] << " ";
            // }
            // cout << endl;
            // cout << index << " " << i << " " << sum << " " << temp[i] << " "
            //  << temp[i - 1] << endl;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;

        // sort(globalArr.begin(), globalArr.end());

        getCombinationSum2(0, n, globalArr, ans, temp, k);

        return ans;
    }
};