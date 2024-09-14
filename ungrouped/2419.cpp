#include "include.h"

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int m = max_element(nums.begin(), nums.end()) - nums.begin();
        int res = 0, x = nums[m];

        // Traverse from nums[m] on
        for (int i = m; i < n; i++) {
            int len = 0;

            // find contiguous subarray with maximum value
            while (i < n && nums[i] == x) {
                i++;
                len++;
            }
            res = max(res, len);
        }
        return res;
    }
};