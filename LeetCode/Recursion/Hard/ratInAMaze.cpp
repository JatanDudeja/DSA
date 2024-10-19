/*
Note:- 
    Keep dead ends before base case because if the current block/case is not valid no need to move forward or event check the base case as base case is checked only when the case is valid
*/


// Not the  best approach as we are using another matrix visited to check if the matrix is visited or not

class Solution
{
public:
    void helper(vector<vector<int>> &arr, vector<string> &ans, string temp, int i, int j, int n, vector<vector<int>> &visited)
    {
        // dead ends:- if the current block/case is not valid no need to move forward or event check the base case
        // as base case is checked only when the case is valid
        if (i >= n || i < 0 || j >= n || j < 0 || arr[i][j] == 0 || visited[i][j] == 1)
            return;
            
        // base case
        if (i == n - 1 && j == n - 1)
        {
            // cout << temp << endl;
            ans.push_back(temp);
            return;
        }

        // mark current position as visited
        visited[i][j] = 1;
        // cout << temp << ", i: " << i << ", j: " << j << endl;
        
        // move up
        helper(arr, ans, temp + 'U', i - 1, j, n, visited);
        // move down
        helper(arr, ans, temp + 'D', i + 1, j, n, visited);
        // move left
        helper(arr, ans, temp + 'L', i, j - 1, n, visited);
        // move right
        helper(arr, ans, temp + 'R', i, j + 1, n, visited);

        // mark current position as 0 again while backtracking
        visited[i][j] = 0;
    }

    vector<string> findPath(vector<vector<int>> &arr)
    {
        // Your code goes here

        vector<string> ans;
        string temp = "";

        int n = arr.size();
        
        vector<vector<int>> visited(n, vector<int>(n, 0));

        helper(arr, ans, temp, 0, 0, n, visited);

        return ans;
    }
};

// Best Solution - without visited matrix
class Solution
{
public:
    void helper(vector<vector<int>> &arr, vector<string> &ans, string temp, int i, int j, int n, vector<vector<int>> &visited)
    {

        if (i >= n || i < 0 || j >= n || j < 0 || arr[i][j] == 0 || arr[i][j] == 2)
            return;
            
        if (i == n - 1 && j == n - 1)
        {
            // cout << temp << endl;
            ans.push_back(temp);
            return;
        }

        // mark the current element as visited by changing 1 to 2 in the given matrix itself
        arr[i][j] = 2;
        // cout << temp << ", i: " << i << ", j: " << j << endl;
        
        // move up
        helper(arr, ans, temp + 'U', i - 1, j, n, visited);
        // move down
        helper(arr, ans, temp + 'D', i + 1, j, n, visited);
        // move left
        helper(arr, ans, temp + 'L', i, j - 1, n, visited);
        // move right
        helper(arr, ans, temp + 'R', i, j + 1, n, visited);

        // mark the current element to 1 in the given matrix itself while backtracking
        arr[i][j] = 1;
    }

    vector<string> findPath(vector<vector<int>> &arr)
    {
        // Your code goes here

        vector<string> ans;
        string temp = "";

        int n = arr.size();
        
        vector<vector<int>> visited(n, vector<int>(n, 0));

        helper(arr, ans, temp, 0, 0, n, visited);

        return ans;
    }
};