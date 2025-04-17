#include "include.h"

class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        string res = "";

        for (char c : s) {
            if (c == ')') {
                string tmp = "";
                while (!st.empty() && st.top() != '(') {
                    tmp += st.top();
                    st.pop();
                }
                if (!st.empty()) st.pop(); // pop the '('
                for (int i = 0; i < tmp.size(); i++) {
                    st.push(tmp[i]);
                }
            } else {
                st.push(c);
            }
        }

        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};