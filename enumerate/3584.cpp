#include "include.h"

class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        long long res = LLONG_MIN;
        int mini = INT_MAX, maxi = INT_MIN;
        for (int i = m - 1; i < nums.size(); i++) {
            // [0, i - m + 1]
            int tmp = nums[i - m + 1];
            mini = min(mini, tmp);
            maxi = max(maxi, tmp);
            // enumerate right
            long long x = nums[i];
            res = max({res, x * mini, x * maxi});
        }
        return res;
    }
};