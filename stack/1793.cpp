#include "include.h"

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int res = nums[k], mini = nums[k];
        int left = k, right = k;
        while (left > 0 || right < n - 1) {
            if ((left > 0 ? nums[left - 1] : 0) < (right < n - 1 ? nums[right + 1] : 0))
                mini = min(mini, nums[++right]);
            else
                mini = min(mini, nums[--left]);
            res = max(res, mini * (right - left + 1));
        }
        return res;
    }
};