#include "include.h"

// Prefix Sum
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size(), len = INT_MAX;
        vector<int> sums(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        for (int i = n; i >= 0 && sums[i] >= s; i--) {
            int j = upper_bound(sums.begin(), sums.end(), sums[i] - s) - sums.begin();
            len = min(len, i - j + 1);
        }
        return len == INT_MAX ? 0 : len;
    }
};

// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;

        int ans = INT_MAX;
        int cur = 0;
        for(int right = 0; right < n; right++) {
            cur += nums[right];
            while(cur >= target) {
                ans = min(ans, right - left + 1);
                cur -= nums[left];
                left++;
            }                
        }

        if(ans == INT_MAX)
            return 0;

        return ans;
    }
};