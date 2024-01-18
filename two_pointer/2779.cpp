#include "include.h"

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int maxi = 0;
        int left = 0;
        int target = 2 * k;
        for(int i = 0; i < n; i++) {
            while(nums[i] - nums[left] > target) {
                left++;
            }
            maxi = max(maxi, i - left + 1);
        }
        return maxi;
    }
};