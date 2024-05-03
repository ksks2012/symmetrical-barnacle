#include "include.h"

// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int res = nums[k], mini = nums[k];
        int left = k, right = k;
        // start from left = right = k, score = nums[k]
        // reduce the min(nums[i]..nums[j]) slowly
        while (left > 0 || right < n - 1) {
            // A[left - 1] < A[right + 1]
            if ((left > 0 ? nums[left - 1] : 0) < (right < n - 1 ? nums[right + 1] : 0))
                mini = min(mini, nums[++right]);
            // A[left - 1] >= A[right + 1]   
            else
                mini = min(mini, nums[--left]);
            res = max(res, mini * (right - left + 1));
        }
        return res;
    }
};