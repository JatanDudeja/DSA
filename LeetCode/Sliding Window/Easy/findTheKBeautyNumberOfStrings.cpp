#include <stdlib.h>

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int i = 0;
        int j = 0;

        string s = to_string(num);
        int n = s.size();
        string t = "";
        int ans = 0;

        while (j < n) {
            t += s[j];
            // cout << "entry: " << j << ", " << t << endl;

            if ((j - i + 1) > k) {
                t.erase(0, 1);
                // cout << "in if > k: " << j << ", " << t << endl;
                i++;
            }

            if ((j - i + 1) == k) {
                // cout << "in else <= k before: " << j << ", " << t << endl;

                int newT = stoi(t);
                // cout << "in else <= k after: " << j << ", " << t << endl;

                if (newT != 0 && num % newT == 0)
                    ans++;
            }
            j++;
        }

        return ans;
    }
};