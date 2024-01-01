#include "include.h"

class Solution {
   public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        int ans = -1;

        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }
        if(sum < x)
            return -1;

        int target = sum - x;

        int left = 0;
        int cur = 0;
        for(int right = 0; right < n; ++right) {
            cur += nums[right];
            while(cur > target) {
                cur -= nums[left];
                left++;
            }
            if(cur == target)
                ans = max(ans, right - left + 1);
        }

        if(ans == -1) {
            return -1;
        }

        return n - ans;
    }
};