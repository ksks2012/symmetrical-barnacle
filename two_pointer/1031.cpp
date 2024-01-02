#include "../include.h"

// DP
class Solution {
public:
    int maxTwoNoOverlap(vector<int> &nums, int L, int M, int sz, int res = 0) {
        vector<int> left(sz + 1), right(sz + 1);
        for (int i = 0, j = sz - 1, s_r = 0, s_l = 0; i < sz; ++i, --j) {
            s_l += nums[i], s_r += nums[j];
            left[i + 1] = max(left[i], s_l);
            right[j] = max(right[j + 1], s_r);
            if (i + 1 >= L)
                s_l -= nums[i + 1 - L];
            if (i + 1 >= M)
                s_r -= nums[j + M - 1];
        }
        for (auto i = 0; i < nums.size(); ++i) {
            res = max(res, left[i] + right[i]);
        }
        return res;
    }

    int maxSumTwoNoOverlap(vector<int> &nums, int L, int M) {
        return max(maxTwoNoOverlap(nums, L, M, nums.size()), maxTwoNoOverlap(nums, M, L, nums.size()));
    }
};