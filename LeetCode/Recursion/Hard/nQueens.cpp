// This is not the best approach as we are calculation conflicts in 3 directions which can add three O(n) complexities so the better approach is mentioned after this approach

class Solution {
public:
    bool checkConflict(vector<string>& arr, int i, int j, int size) {
        // check above
        for (int m = i; m >= 0; m--) {
            if (arr[m][j] == 'Q')
                return true;
        }

        // check upper left diagonal
        int m = i, n = j;
        while (m >= 0 && n >= 0) {
            if (arr[m][n] == 'Q')
                return true;
            m--;
            n--;
        }

        // check upper right diagonal
        m = i, n = j;
        while (m >= 0 && n < size) {
            if (arr[m][n] == 'Q')
                return true;
            m--;
            n++;
        }

        return false;
    }

    void helper(int n, vector<vector<string>>& arr, int i,
                vector<string> temp) {
        if (i >= n) {
            arr.push_back(temp);
            return;
        }

        // where z = each column
        for (int z = 0; z < n; z++) {
            // check if queen can be placed or not
            // if check conflict returns true it means there is conflict
            // and queen cannot be placed at that position
            if (checkConflict(temp, i, z, n))
                continue;

            temp[i][z] = 'Q'; // if no conflicts then add Queen to the the
                              // current position
            helper(n, arr, i + 1, temp);
            temp[i][z] =
                '.'; // remove the added Queen to empty place while backtracking
                     // to get to the previous state of the recursion
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;
        vector<string> temp;
        string s = "";

        // make a string with . which shows that the Queen is not placed
        // anywhere yet
        for (int i = 0; i < n; i++) {
            s += '.';
        }

        // push the above string s in temp
        for (int i = 0; i < n; i++) {
            temp.push_back(s);
            // cout << temp[i] << endl;
        }

        helper(n, ans, 0, temp);

        return ans;
    }
};



// Best Solution Using 3 Extra Vectors for checking if it is safe to place the queen at a position

class Solution {
public:
    void helper(int n, vector<vector<string>>& arr, int i, vector<string> temp,
                vector<int> checkAbove,
                vector<int> checkLeftUpperDiagonal,
                vector<int> checkRightUpperDiagonal) {
        if (i >= n) {
            arr.push_back(temp);
            return;
        }

        // where z = each column
        for (int z = 0; z < n; z++) {
            // check if queen can be placed or not
            // if check conflict returns true it means there is conflict
            // and queen cannot be placed at that position
            if (checkAbove[z] || checkLeftUpperDiagonal[(n - 1) + (z - i)] ||
                checkRightUpperDiagonal[i + z])
                continue;

            temp[i][z] = 'Q'; // if no conflicts then add Queen to the the
                              // current position
            checkAbove[z] = 1;
            checkLeftUpperDiagonal[(n - 1) + (z - i)] = 1;
            checkRightUpperDiagonal[i + z] = 1;


            helper(n, arr, i + 1, temp, checkAbove, checkLeftUpperDiagonal,
                   checkRightUpperDiagonal);

                   
            temp[i][z] =
                '.'; // remove the added Queen to empty place while backtracking
                     // to get to the previous state of the recursion
            checkAbove[z] = 0;
            checkLeftUpperDiagonal[(n - 1) + (z - i)] = 0;
            checkRightUpperDiagonal[i + z] = 0;
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;
        vector<string> temp;
        string s = "";

        vector<int> checkAbove(n);
        vector<int> checkLeftUpperDiagonal(2 * n - 1);
        vector<int> checkRightUpperDiagonal(2 * n - 1);

        // make a string with . which shows that the Queen is not placed
        // anywhere yet
        for (int i = 0; i < n; i++) {
            s += '.';
        }

        // push the above string s in temp
        for (int i = 0; i < n; i++) {
            temp.push_back(s);
            // cout << temp[i] << endl;
        }

        helper(n, ans, 0, temp, checkAbove, checkLeftUpperDiagonal, checkRightUpperDiagonal);

        return ans;
    }
};