// Solution with more time complexity - Self Made

class Solution {
public:
    void getCombinationSum2(vector<int> arr, int sum, int currentSum,
                            set<vector<int>>& ans, int i, int n,
                            vector<int> temp) {
        if (i >= n) {
            if (currentSum == sum){
                sort(temp.begin(), temp.end());
                ans.insert(temp);
            }
            return;
        }

        temp.push_back(arr[i]);
        currentSum += arr[i];
        getCombinationSum2(arr, sum, currentSum, ans, i + 1, n, temp);
        temp.pop_back();
        currentSum -= arr[i];
        getCombinationSum2(arr, sum, currentSum, ans, i + 1, n, temp);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> tempAns;
        vector<int> temp;

        getCombinationSum2(candidates, target, 0, tempAns, 0, candidates.size(),
                           temp);

        vector<vector<int>> ans;

        for (auto i : tempAns) {
            ans.push_back(i);
        }

        return ans;
    }
};



// ------------------------------------------------------------------------------

// Solution with Better Time Complexity - Took help from Striver's video

class Solution {
public:
    void getCombinationSum2(int index, int sum, vector<int>& arr,
                        vector<vector<int>>& ans, vector<int>& temp) {
    if (sum == 0) {
        ans.push_back(temp);
        return;
    }

    for (int i = index; i < arr.size(); i++) {

        /*
        if the current index element and the previous
        element in the given candidates array is same we
        do not do the recursion calls to find the solution
        for that element instead we just continue
        */
       
        if (i > index && arr[i - 1] == arr[i]) {
            // cout << "In continue: " << endl;
            // cout << index << " " << i << " " << sum << endl;
            // for (int j = 0; j < temp.size(); j++) {
            //     cout << temp[i] << " ";
            // }
            // cout << endl;
            continue;
        }


        /*
        if the current sum / target sum is less than the current element to be picked
        then it is not possible to pick as the sum will get negative and that should not happen
        so we just break the recursion call returns to previous waiting call
        */

        if (sum < arr[i]) {
            // cout << "In break: " << endl;
            // cout << index << " " << i << " " << sum << endl;
            // for (int j = 0; j < temp.size(); j++) {
            //     cout << temp[i] << " ";
            // }
            // cout << endl;
            break;
        }

        // just push the element
        temp.push_back(arr[i]);


        // cout << "Before Recur: " << endl;
        // cout << index << " " << i << " " << sum << endl;
        // for (int j = 0; j < temp.size(); j++) {
        //     cout << temp[i] << " ";
        // }
        // cout << endl;

        /*
        call the recursion by increasing the index and reducing the target/sum by
        subtracting the current element
        */
        getCombinationSum2(i + 1, sum - arr[i], arr, ans, temp);

        /*
        after recursion just remove the currently added element
        to pick the next element from the candidates array or 
        the given array
        */ 

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

vector<vector<int>> combinationSum2(vector<int> arr, int target) {
    vector<vector<int>> ans;
    vector<int> temp;

    sort(arr.begin(), arr.end());

    getCombinationSum2(0, target, arr, ans, temp);
    // findCombination(0, target, arr, ans, ds);

    return ans;
}
};