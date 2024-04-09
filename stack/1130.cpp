#include "../include.h"

// lee
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int res = 0;
        vector<int> st = {INT_MAX};
        for (int a : arr) {
            while (st.back() <= a) {
                int mid = st.back();
                st.pop_back();
                res += mid * min(st.back(), a);
            }
            st.push_back(a);
        }
        for (int i = 2; i < st.size(); ++i) {
            res += st[i] * st[i - 1];
        }
        return res;
    }
};