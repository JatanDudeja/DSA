// Best Solution is Below this

// Recursion Code not the best solution

class Solution {
public:
    bool checkValid(stack<char>& st, string& s, int i, int n) {
        if (i == n || n == 0) {
            return true;
        }

        if (st.size() == 0 && (s[i] == ')' || s[i] == '}' || s[i] == ']'))
            return false;

        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        } else {
            int top = st.top();
            if (s[i] == ')') {
                if (top == '(')
                    st.pop();
                else
                    return false;
            }

            if (s[i] == '}') {
                if (top == '{')
                    st.pop();
                else
                    return false;
            }

            if (s[i] == ']') {
                if (top == '[')
                    st.pop();
                else
                    return false;
            }
        }

        return checkValid(st, s, i + 1, n);
    }

    bool isValid(string s) {
        stack<char> st;
        bool ans = checkValid(st, s, 0, s.size());

        if(ans && st.size() == 0) return true;
        return false;
    }
};

// Best Solution
// T.C. - O(N)
// S.C. - O(N)
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(auto i : s){
            if(i == '(' || i == '{' || i == '[') st.push(i);

            else if(st.empty() && (i == ')' || i == '}' || i == ']')) return false;

            else if(!st.empty()){
                char top = st.top();

                if(i == ')' && top != '(' || i == '}' && top != '{' || i == ']' && top != '[') return false;

                st.pop();
            }

        }

        if(st.size() == 0) return true;

        return false;
    }
};