class Solution {
public:
    vector<string> ans;
    void helper(string& s, int i, long prev, string tempString, int target,
                long sum) {
        if (i >= s.size()) {
            if (sum == target) {
                ans.push_back(tempString);
            }
            return;
        }

        int num = s[i] - '0';

        for (int j = i; j < s.size(); j++) {
            if (j > i && s[i] == '0')
                return;

            long num = stol(s.substr(i, j - i + 1));

            if (i == 0) {
                helper(s, j + 1, num, tempString + s.substr(i, j - i + 1),
                       target, num);
            } else {
                helper(s, j + 1, num, tempString + '+' + s.substr(i, j - i + 1),
                       target, sum + num);
                helper(s, j + 1, num * prev,
                       tempString + '*' + s.substr(i, j - i + 1), target,
                       sum - (prev) + (prev * num));
                helper(s, j + 1, -num,
                       tempString + '-' + s.substr(i, j - i + 1), target,
                       sum - num);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        helper(num, 0, 0, "", target, 0);
        return ans;
    }
};