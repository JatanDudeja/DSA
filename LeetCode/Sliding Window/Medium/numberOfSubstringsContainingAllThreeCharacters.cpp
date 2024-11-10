
// Not the best Solution:- 

// Explanation:- https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/solutions/3459766/explained-w-images-made-easy-c

class Solution {
public:
    int getSubArrayCount(string s){
        int i = 0;
        int j = 0;
        int n = s.size();
        int ans = 0;
        unordered_map<char, int> m;

         while(j < n){
            m[s[j]]++;

            while(m['a'] >= 1 && m['b'] >= 1 && m['c'] >= 1){
                ans += (n - j);
                m[s[i]]--;
                i++;
            }

            j++;

        }

        return ans;

    }
    int numberOfSubstrings(string s) {
        int i = 0;
        int j = 0;
        int n = s.size();
        int ans = 0;

        return getSubArrayCount(s);
        
    }
};