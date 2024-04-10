#include "../include.h"

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> st;
        vector<int> res(nums.size(), -1);
        int n = nums.size();
        for(int i = 0; i < n * 2; i++) {
            int idx = i % n;
            while(!st.empty() && nums[st.back()] < nums[idx]) {
                res[st.back()] = nums[idx];
                st.pop_back();
            }
            st.push_back(idx);
        }
        
        return res;
    }
};