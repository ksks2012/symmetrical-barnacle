#include "include.h"

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int incr = 0, decr = 0;

        for(; right < nums.size(); right++) {
            if(right > 0 && nums[right] <= nums[right - 1]) {
                left = right;
            }
            incr = max(incr, right - left + 1);
        }

        left = 0;
        for(right = 0; right < nums.size(); right++) {
            if(right > 0 && nums[right] >= nums[right - 1]) {
                left = right;
            }
            decr = max(decr, right - left + 1);
        }

        return max(incr, decr);      
    }
};
