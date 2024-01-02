#include "../include.h"

// lee
class Solution {
public:
    int helper(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        int left = 0;

        for(int right = 0; right < n; right++) {
            k -= nums[right] % 2;
            while (k < 0) {
                k += nums[left++] % 2;
            }
            ans += right - left + 1;
        }

        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k - 1);
    }
};