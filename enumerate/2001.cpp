#include "include.h"

class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, long long> cnt;

        for (auto& r : rectangles) {
            double ratio = (double)r[0] / r[1];
            cnt[ratio]++;
        }

        long long res = 0;
        for (auto& [k, v] : cnt) {
            res += v * (v - 1) / 2;
        }

        return res;
    }
};