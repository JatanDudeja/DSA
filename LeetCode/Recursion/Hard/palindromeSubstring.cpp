/*

Approach:- We will pass the new substring to the function in every call after
doing a parition. Eg:- Input: s = "aab" Output: ["a","aa","b"]

in first call the string passed will be aab
then a new substring will be created in newString = a
then we will check if it is palindrome if
yes:
    then we will create a string afterPalindromeString which will have value as
    ab then will we add newString in the vector and then we will call recusion with
    the new string i.e. the afterPalindromeString = ab
no: we will simply continue

*/

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        // cout << "s: " << s << endl;
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }

        return true;
    }

    void partitionHelper(string s, int index, vector<vector<string>>& ans,
                         vector<string> temp) {
        // cout << "in" << endl;
        if (index >= s.size()) {
            // cout << "yoyo" << endl;
            ans.push_back(temp);

            return;
        }

        for (int i = 0; i < s.size(); i++) {
            // create a new string to from index 0 to the current i + 1
            // because in every recusion we will process a new length of the
            // given string
            string newString = s.substr(0, i + 1);

            // check is newly created substring newString is a palindrome or not
            if (!isPalindrome(newString))
                continue; // if not just continue;

            // else pass the other half of the current string that is
            // after the palindromic substring to the new recusive function
            string afterPalindromeString =
                s.substr(i + 1, s.size() - newString.size());

            // then push the newString i.e. palindrome in a vector of string;
            temp.push_back(newString);
            // call recursion
            partitionHelper(afterPalindromeString, index, ans, temp);

            // remove element after recursion or while backtracking
            temp.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> temp;

        partitionHelper(s, 0, ans, temp);

        return ans;
    }
};