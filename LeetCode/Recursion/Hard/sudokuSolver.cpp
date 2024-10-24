class Solution {
public:
    bool checkIfValuePossible(vector<vector<char>>& arr, int i, int j, int z) {
        for (int m = 0; m < 9; m++) {
            if (arr[m][j] == z) // check every row in the same column
                return false;
            if (arr[i][m] == z) // check every column keeping the row same
                return false;
            if (arr[3 * (i / 3) + (m / 3)][3 * (j / 3) + (m % 3)] == z) // check in a sub matrix 3 * 3
                return false;
        }

        return true;
    }

    bool helper(vector<vector<char>>& arr) {
        // check for every column if there is . present
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (arr[i][j] == '.') {
                    // then put 1-9 in the place of . one by one and do recursion for every case
                    for (char z = '1'; z <= '9'; z++) {
                        // before doing recursion check the given conditions
                        // on that basis check if recursion should be done or not
                        if (!checkIfValuePossible(arr, i, j, z))
                            continue;
                        // if all conditions are true put the current value between 1 to 9 at the place of .
                        arr[i][j] = z;
                        // do recursion after all recusion for this particualr value have been done check if it is true or not if true then return true
                        /*
                        Note if at any value the recursion is true it will never reach backtracking at this
                        point it will always return true if at any points a value does not satisy then it will
                        backtrack and put . again at its position and return false directly without moving
                        finding the next empty or position with .
                        */
                        if (helper(arr) == true)
                            return true;
                        // else just do backtracking and put . at its original value
                        arr[i][j] = '.';
                    }
                    // and then return false
                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& arr) {
        bool ans = helper(arr);
        return;
    }
};