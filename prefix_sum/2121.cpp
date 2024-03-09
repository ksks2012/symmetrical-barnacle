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

// endlesscheng
class Solution {
public:
    vector<long long> getDistances(vector<int> &arr) {
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < arr.size(); ++i) {
            // record idx of same element
            pos[arr[i]].push_back(i);
        }

        vector<long long> ans(arr.size());
        // for all pair
        for (auto &[_, p] : pos) {
            long sum = 0L;
            // sum of first interval in pair
            for (int i : p) 
                sum += i - p[0];
            ans[p[0]] = sum;
            for (int i = 1, n = p.size(); i < n; ++i)
                // calculate sum of next interval in next pair
                ans[p[i]] = sum += (2L * i - n) * (p[i] - p[i - 1]);
        }
        return ans;
    }
};