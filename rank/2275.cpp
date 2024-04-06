#include "../include.h"

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int res = 0, maxi = *max_element(begin(candidates), end(candidates));
        for (int b = 1; b <= maxi; b <<= 1) {
            int cnt = 0;
            for (auto n : candidates)
                cnt += (n & b) > 0;
            res = max(res, cnt);
        }
        return res;
    }
};