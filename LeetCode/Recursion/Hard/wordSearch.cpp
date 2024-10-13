class Solution {
public:
    bool checkWord(vector<vector<char>> &arr, string word, int i, int j, int m,
                   int n, int k) {
        // if k reaches the end of the given string that is to be found
        // in the matrix we defintely know that we have found the word
        if (k >= word.size()) {
            return true;
        }

        /*
        if at any point i/j becomes less than 0 or
        i >= number of rows in the matrix or j >= the number of columns in that row or
        the currect letter of the matrix does not match with current letter of the given string or
        the current letter of the matrix has already been used as we cannot reuse a char so
        then we just return false
        */
        if (i < 0 || j < 0 || i >= m || j >= n || arr[i][j] != word[k] ||
            arr[i][j] == '!') {
            return false;
        }

        /*
        in every iteration we just make the current letter in the matrix as !
        so that we can figure that we should not use it now again
        and we only make it ! after it passes the above if condition which states
        that current letter of the matrix should not equal the current letter
        in the given string so know if the above if condition is passing the
        current letter in the matrix == current letter of the given string/word
        */
        char c = arr[i][j];
        arr[i][j] = '!';

        // we then do recursion in all four directions
        bool top = checkWord(arr, word, i - 1, j, m, n, k + 1);
        bool right = checkWord(arr, word, i, j + 1, m, n, k + 1);
        bool down = checkWord(arr, word, i + 1, j, m, n, k + 1);
        bool left = checkWord(arr, word, i, j - 1, m, n, k + 1);

        /*
        while backtracking or after all fours recursions have been done
        we restore the current letter to its original character so that
        it can be used again in the next iteration of the recursion
        */
        arr[i][j] = c;

        // here we just return the output from all the four recursions
        return top || right || down || left;
    }

    bool exist(vector<vector<char>>& arr, string word) {
        int m = arr.size();
        int n = arr[0].size();
        int k = 0;

        // find the first character in the matrix of the given word
        for (int i = 0; i < m; i++) {
            bool checked = false;
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == word[k]) {
                    // for every match in matrix of the first character of the given word call recursion
                    checked = checkWord(arr, word, i, j, m, n, k);
                    if (checked) return true;
                }
            }
        }

        return false;
    }
};