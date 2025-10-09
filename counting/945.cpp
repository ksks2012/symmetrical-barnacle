#include "include.h"

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] <= nums[i - 1]) {
                int incr = nums[i - 1] + 1 - nums[i];
                res += incr;
                nums[i] += incr;
            }
        }
        return res;      
    }
};