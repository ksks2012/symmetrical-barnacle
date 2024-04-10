#include "../include.h"

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temper) {
        int n = temper.size();
        vector<int> st;
        vector<int> res(n, 0);

        for(int i = 0; i < n; i++) {
            while(!st.empty() && temper[st.back()] < temper[i]) {
                res[st.back()] = i - st.back();
                st.pop_back();
            }
            st.push_back(i);
        }

        return res;
    }
};