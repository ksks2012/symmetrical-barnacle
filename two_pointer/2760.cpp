#include "../include.h"

class Solution {
public:
    int longestAlternatingSubarray(vector<int> &nums, int threshold) {
        int n = nums.size();
        int res = 0, right = 0;
        while (right < n) {
            if (nums[right] > threshold || nums[right] % 2) {
                right++;
                continue;
            }
            int left = right; 
            right++; 
            while (right < n && nums[right] <= threshold && nums[right] % 2 != nums[right - 1] % 2) {
                right++;
            }
            res = max(res, right - left);
        }
        return res; 
    }
};
