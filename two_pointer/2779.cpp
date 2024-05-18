#include "include.h"

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int maxi = 0;
        int left = 0;
        // max - min <= k * 2
        int target = 2 * k;
        for(int right = 0; right < n; right++) {
            while(nums[right] - nums[left] > target) {
                left++;
            }
            maxi = max(maxi, right - left + 1);
        }
        return maxi;
    }
};