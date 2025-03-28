#include "include.h"

class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp(n + 1); 
        partial_sum(nums.begin(), nums.end(), tmp.begin() + 1);

        int res = 0;
        for (int i = 0; i < n; i++) {
            res += tmp[i + 1] - tmp[max(i - nums[i], 0)];
        }
        return res;
    }
};
