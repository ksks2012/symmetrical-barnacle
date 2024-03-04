#include "include.h"

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_map<int, int> dp{{0, -1}};
        int n = nums.size();
        int sum = 0, right = -1, ans = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            // sum - target
            if (dp.count(sum - target)) {
                int left = dp[sum - target];
                if (right <= left) {
                    ++ans;
                    // follow minimum right index
                    // update right
                    right = i;
                }
            }
            dp[sum] = i;
        }
        return ans;
    }
};