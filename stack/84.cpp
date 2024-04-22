#include "include.h"

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        vector<int> st;
        int res = 0;

        for(int i = 0; i < heights.size(); i++) {
            while(!st.empty() && heights[st.back()] >= heights[i]) {
                int tmp = heights[st.back()];
                st.pop_back();

                int idx = st.size() > 0 ? st.back() : -1;
                res = max(res, tmp * (i - idx - 1));
            } 
            st.push_back(i);
        }

        return res;
    }
};