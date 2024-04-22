class Solution {
public:
    long long helperAtoi(string& s, int i, long long ans, int n, int sign) {
        // cout << i << ' ' << s[i] << endl;
        if (i == n) {
            return ans;
        }

        if (s[i] >= '0' && s[i] <= '9') {   // convert the char in the string to number
            // cout << i << ' ' << ans << ' ' << s[i] << endl;
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && s[i] - '0' > 7)) {
                return sign == '-' ? INT_MIN : INT_MAX;
            }
            ans = ans * 10 + (int)(s[i] - '0');
            return helperAtoi(s, i + 1, ans, n, sign);
        }

        return ans; // return ans if anything other that number char is found
    }

    int myAtoi(string s) {
        int n = s.length();
        long long ans = 0;
        bool visited = false;
        char sign = ' ';
        int i = 0;

        for (; i < n; i++) {    // removed spaced
            if (s[i] == ' ')
                continue;
            else
                break;
        }

        if (s[i] == '-') {  // got the sign
            sign = '-';
            i++;
        } else if(s[i] == '+') {
            sign = '+';
            i++;
        }
        else{
            sign = '+';
        }
        // cout << i << ' ' << s[i] << endl;

        long long finalAns = (sign == '-') ? -helperAtoi(s, i, ans, n, sign) : helperAtoi(s, i, ans, n, sign);

        return (int)finalAns;
    }
};