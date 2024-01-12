#include "include.h"

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> ans(n, -1);
        long long cur = 0;
        int mod = k * 2 + 1;
        if(n < mod)
            return ans;

        for(int i = 0; i < n; i++) {
            // Add nums[i] to the window sum
            cur += nums[i];

            if(i - mod >= 0) {
                // Remove nums[i - mod] from the window sum
                cur -= nums[i - mod];
            }
            if(i >= mod - 1) {
                // Calculate and store the average in the result
                ans[i - k] = cur / mod;
            }
        }

        return ans;
    }
};