#include "include.h"

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> st;
        for(int i = 0; i < n; i++) {
            if(!st.empty() && arr[st.back()] > arr[i]) {
                int top = st.back();
                while(!st.empty() && arr[st.back()] > arr[i]) {
                    st.pop_back();
                }
                st.push_back(top);
            } else {
                st.push_back(i);
            }

        }
        return st.size();
    }
};

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 0;
        int maxi = 0;

        for (int i = 0; i < arr.size(); i++) {
            maxi = max(maxi, arr[i]);

            if (i == maxi) {
                res++;
            }
        }

        return res;
    }
};