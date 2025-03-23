#include "include.h"

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int res = 0;
        int mini = INT_MAX / 2, maxi = INT_MIN / 2;
        for (auto& a : arrays) {
            res = max({res, a.back() - mini, maxi - a[0]});
            mini = min(mini, a[0]);
            maxi = max(maxi, a.back());
        }
        return res;
    }
};