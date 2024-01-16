#include "include.h"

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        // range
        int left = 0, right = 0;
        int j = 0;

        for(int i = 0; i < n; i++) {
            if(i == 0) {
                ans = ans + 1;
                left = nums[i] - 2;
                right = nums[i] + 2;
            } else if(nums[i] >= left && nums[i] <= right) {
                left = max(left, nums[i] - 2);
                right = min(right, nums[i] + 2);
                ans = ans + (i - j + 1);
            } else {
                j = i - 1;
                left = nums[i] - 2;
                right = nums[i] + 2;
                while(nums[j] >= nums[i] - 2 && nums[j] <= nums[i] + 2) {
                    left = max(left, nums[j] - 2);
                    right = min(right, nums[j] + 2);
                    j--;
                }
                j++;
                ans = ans + (i - j + 1);
            }
        }

        return ans;        
    }
};