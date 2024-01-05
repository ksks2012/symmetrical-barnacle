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

// prefix sum
class Solution {
public:
    int n;
    vector<int> prefixSum;
    int maxSum(int L, int M) {
        int maxL = 0, ans = 0;
        for(int i = L + M; i <= n; ++i) {
            maxL = max(maxL, prefixSum[i - M] - prefixSum[i - L - M]);
            ans = max(ans, maxL + prefixSum[i] - prefixSum[i - M]);
        }
 
        return ans;
    }

    int maxSumTwoNoOverlap(vector<int> &nums, int L, int M) {
        n = nums.size();
        prefixSum = vector<int>(n + 1, 0);
        for(int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        return max(maxSum(L, M), maxSum(M, L));
    }
};