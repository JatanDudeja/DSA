class Solution {
public:
    void getGeneratedParenthesis(int n, int o, int c, vector<string>& ans,
                                 string temp) {

        // if the count of the both the open and close bracket has become 0 then just push
        // the string in the arrau
        if (o <= 0 && c <= 0) {
            ans.push_back(temp);
            return;
        }
        
        // open brackets can only be inserted if any open bracket count is still greater than 0
        if (o > 0) {
            // create a new string
            string newS = temp;
            // push back opening bracket
            newS.push_back('(');
            getGeneratedParenthesis(n, o - 1, c, ans, newS);
        } 
        
        // and closing bracket can only come if count of closing bracket is greater than
        // the count of the opening bracket because if the closing brackets finish up before
        // the opening brackets the parenthesis can never be balanced
        if(c > o){
            // create a new string
            string newS = temp;
            // push back opening bracket
            newS.push_back(')');
            getGeneratedParenthesis(n, o, c - 1, ans, newS);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        getGeneratedParenthesis(n, n, n, ans, "");

        return ans;
    }
};