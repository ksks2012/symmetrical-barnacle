#include "include.h"

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> res(n, -1);
        long long cur = 0;
        int mod = k * 2 + 1;
        if(n < mod)
            return res;

        for(int right = 0; right < n; right++) {
            // Add nums[i] to the window sum
            cur += nums[right];

            if(right - mod >= 0) {
                // Remove nums[i - mod] from the window sum
                // left = right - mod
                cur -= nums[right - mod];
            }
            if(right >= mod - 1) {
                // Calculate and store the average in the result
                res[right - k] = cur / mod;
            }
        }

        return res;
    }
};