// Brute Force
class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            int count0 = 0, count1 = 0;
            int j;
            for(j = i; j < n; j++){
                if(s[j] == '1'){
                    count1++;
                }
                else if(s[j] == '0'){
                    count0++;
                }

                if(count0 > k && count1 > k) break;
                else ans++;
            }
            // cout << s[i] << ", " << i << ", " << j << ", " << count0 << ", " << count1 << endl;
            // if(calLength == true){
            //     ans++;
            // }
        }


        return ans;
    }
};


// Best Approach - Sliding Window

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.size();
        int ans = 0;

        int count0 = 0, count1 = 0;

        int i = 0, j = 0;

        while (j < n) {
            if (s[j] == '1') {
                count1++;
            } else if (s[j] == '0') {
                count0++;
            }

            while (count0 > k && count1 > k) {
                if (s[i] == '1') {
                    count1--;
                } else if (s[i] == '0') {
                    count0--;
                }
                i++;
            }

            // adding the lenght to the ans
            // as each valid substring can have substring.length
            // valid ans for eg if s = "10101" and k = 1 and one
            // of the subtrings is 101 then we can see 1, 10, 101 all are valid substring
            ans = ans + j - i + 1;
            j++;
        }

        return ans;
    }
};