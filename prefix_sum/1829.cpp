#include "include.h"

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int val = (1 << maximumBit) - 1;
        for (int i = 0; i < n; ++i)
            ans[n - i - 1] = val ^= nums[i];
        return ans;
    }
};