#include "include.h"

class Solution {
public:
    string removeDuplicates(string s) {
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if(st.empty()) {
                st.push(s[i]);
                continue;
            }
            if(s[i] == st.top()) {
                st.pop();
            } else {
                st.push(s[i]);
            }

        }
        string res = "";
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end()); 
        return res;
    }
};