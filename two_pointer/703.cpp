#include "include.h"

// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k < 1)
            return 0;

        int ans = 0;
        int n = nums.size();
        int left = 0;
        int tmp = 1;
        for(int i = 0; i < n; i++) {
            tmp *= nums[i];
            while(tmp >= k) {
                tmp /= nums[left];
                left++;
            }
            ans += i - left + 1;
        }
        return ans;
    }
};