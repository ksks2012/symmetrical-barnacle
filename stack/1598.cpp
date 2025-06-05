#include "include.h"

class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;
        for (const string& log : logs) {
            if (log == "../") {
                if (!st.empty()) {
                    st.pop();
                }
            } else if (log == "./") {
                continue; // Do nothing
            } else {
                st.push(log); // Push the directory onto the stack
            }
        }
        return st.size(); // The size of the stack is the number of directories in the current path
    }
};