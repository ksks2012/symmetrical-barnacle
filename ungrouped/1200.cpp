#include "include.h"

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;

        sort(arr.begin(), arr.end());
        int minDiff = INT_MAX;
        for(int i = 1; i < arr.size(); i++) {
            int diff = arr[i] - arr[i - 1];
            if(diff < minDiff) {
                minDiff = diff;
                res.clear();
            }
            if(diff == minDiff) {
                res.push_back({arr[i - 1], arr[i]});
            }
        }
        if(res.empty()) {
            return {{-1, -1}};
        }

        return res;
    }
};