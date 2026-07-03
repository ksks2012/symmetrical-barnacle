#include "../include.h"

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int res = 0;
        int zero = 0;
        for(int right = 0; right < n; right++) {
            if(nums[right] == 0) {
                zero++;
            }
            while(zero > 1) {
                if(nums[left] == 0) zero--;
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};