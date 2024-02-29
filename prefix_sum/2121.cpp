#include "include.h"

class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<int, vector<int>> m;
        vector<long long> ans(arr.size());
        for (int i = 0; i < arr.size(); i++) {
            m[arr[i]].push_back(i);
        }
        for (auto i = m.begin(); i != m.end(); i++) {
            vector<int> index = i -> second;
            vector<long long> pre(index.size() + 1, 0);
            for (int j = 0; j < index.size(); j++) 
                pre[j + 1] = pre[j] + index[j];
            for (int j = 0; j < index.size(); j++) {
                long long v = index[j];
                ans[index[j]] = (v * (j + 1) - pre[j + 1]) 
                    + ((pre[index.size()] - pre[j]) - v * (index.size() - (j)));
            }
        }
        return ans;
    }
};