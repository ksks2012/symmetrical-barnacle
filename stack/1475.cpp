#include "../include.h"

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> res(n);
        stack<int> st;
        for(int i = prices.size() - 1; i >= 0; --i) {
            while(!st.empty() && prices[st.top()] > prices[i]) 
                st.pop();
            res[i] = st.empty() ? prices[i] : prices[i] - prices[st.top()];
            st.push(i);
        }

        return res;
    }
};