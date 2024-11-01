/*
Approach:- 
Store the occurences of every character in the map and keep checking if at any point
the length of the map is > 2 which means we now have 3 elements of fruits while there should only
have been 2, so we start removing the occurences of the elements from the left and when we have 0 occurence
of a number we remove that key from the map which makes the size of the map again 2 or less than 2
*/

class Solution {
  public:
    int totalFruits(vector<int> &arr) {
        int l = 0, r = 0;
        int n = arr.size();
        unordered_map<int, int> m;
        int maxLen = 0;
        
        while(r < n){
            m[arr[r]]++;
            
            while(m.size() > 2){
                m[arr[l]]--;
                if(m[arr[l]] == 0) m.erase(arr[l]);
                l++;
            }
            
            maxLen = max(maxLen, r - l + 1);
            
            r++;
            
            
        }
        
        return maxLen;
    }
};