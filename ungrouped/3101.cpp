#include "include.h"

class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        int left = 0;
        int right = 0;

        while (right < n) {
            // Expand the window to the right until it is no longer alternating
            while (right + 1 < n && nums[right] != nums[right + 1]) {
                right++;
            }

            // Count the number of alternating subarrays ending at right
            long long tmp = (right - left + 1);
            res += tmp * (tmp + 1) / 2;

            // Move the left pointer to the right by 1 to start a new window
            left = right + 1;
            right = left;
        }

        return res;
    }
};