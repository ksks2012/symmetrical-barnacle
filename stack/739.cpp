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

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temper) {
        int n = temper.size();
        vector<int> st;
        vector<int> res(n, 0);
        
        // [ 0, 1, 2, 3, 4, 5, 6, 7]
        // [73,74,75,71,69,72,76,73]
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && temper[st.back()] <= temper[i]) {
                st.pop_back();
            }
            if(!st.empty()) {
                res[i] = st.back() - i;
            }
            st.push_back(i);
        }
        return res;
    }
};