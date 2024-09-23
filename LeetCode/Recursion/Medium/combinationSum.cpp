
// My Solution Does a little bit more recursion calls

class Solution
{
public:
    void helper(vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> temp, int i)
    {
        if (i >= candidates.size() || target <= 0)
        {
            if (target == 0)
            {
                ans.push_back(temp);
            }
            return;
        }

        // push the current element in the array
        temp.push_back(candidates[i]);
        // call recursion with the same element as an element be added unlimited number of times
        helper(candidates, target - temp.back(), ans, temp, i); // pick candidate - when we pick then we subtract the candidate picked from target so now we just have to search for (target - candidate[i]) as out new target

        // when we wish not to pick the current element or the target <= 0 then we just pop the last element from temp due to which
        // the target became 0 or we do not wish to include the last element
        temp.pop_back();

        // in that case we move to the next element of the array and then the recursion takes care of the solutions
        helper(candidates, target, ans, temp, i + 1); // don't pick the candidate

        return;
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(candidates, target, ans, temp, 0);

        return ans;
    }
};

// Striver's Solution

class Solution
{
public:
    void helper(vector<int> &candidates, int target, vector<vector<int>> &ans,
                vector<int> temp, int i)
    {
        if (i >= candidates.size() || target <= 0)
        {
            if (target == 0)
            {
                ans.push_back(temp);
            }
            return;
        }

        if (candidates[i] <= target)
        {
            // push the current element in the array
            temp.push_back(candidates[i]);
            // call recursion with the same element as an element be added
            // unlimited number of times
            helper(candidates, target - temp.back(), ans, temp,
                   i); // pick candidate - when we pick then we subtract the
                       // candidate picked from target so now we just have to
                       // search for (target - candidate[i]) as out new target
            // when we wish not to pick the current element or the target <= 0
            // then we just pop the last element from temp due to which the
            // target became 0 or we do not wish to include the last element
            temp.pop_back();
        }

        // in that case we move to the next element of the array and then the
        // recursion takes care of the solutions
        helper(candidates, target, ans, temp,
               i + 1); // don't pick the candidate

        return;
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(candidates, target, ans, temp, 0);

        return ans;
    }
};