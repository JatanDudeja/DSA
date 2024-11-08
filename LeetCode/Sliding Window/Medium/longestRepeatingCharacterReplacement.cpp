
// This is not the best solution, the best solution is below this
// T.C. -> O((N + N) * 26)
// S.C. -> O(N)
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> arr(26);

        int i = 0;
        int j = 0;

        int n = s.size();

        int maxFrequency = 0;
        int maxLen = INT_MIN;

        while(j < n){
            //increase frequency of current character
            arr[s[j] - 'A']++;
            // check if the frequency of current character is max or not
            maxFrequency = max(maxFrequency, arr[s[j] - 'A']);

            // if at any point maxFrequency is greater than k this means we cannot
            // calculate max len of the subarray as we only need at most k operations to be done
            // in this loop we decrease the maxFrequency by removing the frequency of chars from left
            while(((j - i + 1) - maxFrequency) > k){
                arr[s[i] - 'A']--;
                /*we put maxFrequecy to 0 because if it
                is greater than k it is of no use to us
                because when we check in the loop just
                below this line then the max frequency
                will always be the previous maxFrequency
                which was before removing the char from the left
                */
                maxFrequency = 0;

                // in this loop we just get the maxFrequency again
                for(int z = 0; z < 26; z++){
                    maxFrequency = max(maxFrequency, arr[z]);
                }
                i++;
            }

            // if length of subarray - maxFrequency <= k which
            // means this condition is valid and we can calculate max length now
            if(((j - i + 1) - maxFrequency) <= k){
                maxLen = max(maxLen, j - i + 1);
            }

            j++;

        }

        return maxLen;
    }
};



// Best Solution
// T.C. -> O(N)
// S.C. -> O(26)

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> arr(26);

        int i = 0;
        int j = 0;

        int n = s.size();

        int maxFrequency = 0;
        int maxLen = INT_MIN;

        while (j < n) {
            // increase frequency of current character
            arr[s[j] - 'A']++;
            // check if the frequency of current character is max or not
            maxFrequency = max(maxFrequency, arr[s[j] - 'A']);
            // cout << i << ", " << j << ", " << s[j] << ", " << arr[s[j] - 'A']
            // << ", " << maxFrequency << endl;

            // if at any point maxFrequency is greater than k this means we
            // cannot calculate max len of the subarray as we only need at most
            // k operations to be done in condition we just move i to next char
            // and also decrease the frequency of the char at ith position
            if (((j - i + 1) - maxFrequency) > k) {
                arr[s[i] - 'A']--;
                i++;
            }

            // if length of subarray - maxFrequency <= k which
            // means this condition is valid and we can calculate max length now
            if (((j - i + 1) - maxFrequency) <= k) {
                // cout << "in: " << i << ", " << j << ", " << s[j] << ", " <<
                // arr[s[j] - 'A'] << ", " << maxFrequency << endl;
                maxLen = max(maxLen, j - i + 1);
                j++;
            }
        }

        return maxLen;
    }
};