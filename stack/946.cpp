#include "include.h"

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i = 0;
        for(int j = 0; j < pushed.size(); j++) {
            st.push(pushed[j]);
            while(!st.empty() && st.top() == popped[i]) {
                st.pop();
                i++;
            }
        }
        return st.empty();
    }
};