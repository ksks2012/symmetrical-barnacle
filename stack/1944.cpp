#include "include.h"

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        vector<int> res(heights.size());

        vector<int> st;

        for(int i = 0; i < heights.size(); i++) {
            while(!st.empty() && heights[st.back()] <= heights[i]) {
                res[st.back()]++;
                st.pop_back();
            }

            if(!st.empty()) {
                res[st.back()]++;
            }

            st.push_back(i);
        }

        return res;
    }
};