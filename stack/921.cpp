#include "include.h"

class Solution {
public:
    int minAddToMakeValid(string s) {
        int res = 0;

        stack<char> st;

        for (char c : s) {
            if (c == '(') {
                st.push(c);
            } else {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                } else {
                    res++;
                }
            }
        }

        res += st.size();
        
        return res;
    }
};