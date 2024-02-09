#include "include.h"

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int tmp[52] = {};
        for (auto &r : ranges) {
            tmp[r[0]] += 1;
            tmp[r[1] + 1] -= 1;
        }
        for (int i = 1, sum = 0; i <= right; ++i) {
            sum += tmp[i];
            if (i >= left && sum == 0)
                return false;
        }
        return true;
    }
};