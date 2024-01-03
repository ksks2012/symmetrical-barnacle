#include "../include.h"

// DP
class Solution {
public:
    int n;
    int maxTwoNoOverlap(vector<int> &nums, int L, int M, int res = 0) {
        vector<int> left(n + 1), right(n + 1);
        int s_r = 0, s_l = 0;
        for (int i = 0, j = n - 1; i < n; ++i, --j) {
            s_l += nums[i];
            s_r += nums[j];
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
        n = nums.size();
        return max(maxTwoNoOverlap(nums, L, M), maxTwoNoOverlap(nums, M, L));
    }
};