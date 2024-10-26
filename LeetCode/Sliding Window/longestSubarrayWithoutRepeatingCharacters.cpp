// Better Approach T.C. -> O(2N); 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;

        int l = 0, r = 0;
        int maxLen = 0;
        int n = s.size();

        while (r < n) {
            // increase the frequency of the current character
            m[s[r]]++;

            // if the frequency of the current character is > 1 then start
            // moving l and shrink the window size till the frequency of the current
            // element is == 1
            while (m[s[r]] > 1) {
                m[s[l]]--;
                l++;
            }

            // if the frequency of the current character == 1 that means
            // all the characters in the map have frequency 1 as we have checked for
            // every character before coming the the current character
            if (m[s[r]] == 1) {
                maxLen = max(maxLen, r - l + 1);
            }
            // simply move to the next character
            r++;
        }

        return maxLen;
    }
};


// Best Approach T.C. -> O(N)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;

        int l = 0, r = 0;
        int maxLen = 0;
        int n = s.size();

        while (r < n) {
            // if the current is present in the map then start
            // set l to the last index where the current character was seen + 1
            // which shrinks the window size directly without using another loop
            // and update the index of the current character in the map to the
            // current index
            if (m.find(s[r]) != m.end()) {
                l = max(m[s[r]] + 1, l);
            }

            // we push it into the map and map it with the current
            // index r and also calculate the max len and simply
            // move to the next character
            m[s[r]] = r;
            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};