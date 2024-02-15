#include "include.h"

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        // left odd/even and right odd/even
        int left[2] = {}, right[2] = {};

        for(int i = 0; i < n; i++) {
            right[i % 2] += nums[i];
        }

        for(int i = 0; i < n; i++) {
            right[i % 2] -= nums[i];
            ans += left[0] + right[1] == left[1] + right[0];
            left[i % 2] += nums[i];
        }
        return ans;
    }
};