// This solution will give TLE as this questions required DP to get full submitted but still its a great solution just not using DP.
// Same as Palindrome Paritioning Question i.e. palindromeSubstring.cpp file in this folder.

// DP Solution will be added in DP folder and not this one.

class Solution {
public:
    bool checkIfWordExistsInTheGivenDict(string word, unordered_set<string> m){
        if(m.find(word) != m.end()) return true;
        return false;
    }

    void helper(string s, unordered_set<string> m, int n, bool &ans){
        if(n == 0) {
            ans = true;
            return;
        };

        if(ans) return;

        for(int i = 0; i < s.size(); i++){
            string temp = s.substr(0, i + 1);
            bool check = checkIfWordExistsInTheGivenDict(temp, m);

            if(!check) continue;

            string newSubString = s.substr(i + 1);
            // cout << check << ", " << temp << ", " << newSubString << endl;

            helper(newSubString, m, newSubString.size(), ans);

            if(ans) return;
        }

    }

    bool wordBreak(string s, vector<string>& wordDict) {

        bool ans = false;

        unordered_set<string> m;

        for(string s : wordDict) m.insert(s);

        helper(s, m, s.size(), ans);

        return ans;   
    }
};